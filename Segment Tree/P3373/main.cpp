#include <bits/stdc++.h>
#define ll long long
#define left(idx) (idx << 1)
#define right(idx) (idx << 1 | 1)
#define MXN 100005
using namespace std;

typedef struct
{
    ll sum, l, r, add, mul;
} tree_node;

int n, q, m, nums[MXN];
tree_node nodes[MXN << 2];

void push_down(ll node_idx)
{
    tree_node &node = nodes[node_idx], &l_node = nodes[left(node_idx)], &r_node = nodes[right(node_idx)];
    l_node.add = (l_node.add * node.mul + node.add) % m;
    r_node.add = (r_node.add * node.mul + node.add) % m;

    l_node.mul = (l_node.mul * node.mul) % m;
    r_node.mul = (r_node.mul * node.mul) % m;

    l_node.sum = (l_node.sum * node.mul + node.add * (l_node.r - l_node.l + 1)) % m;
    r_node.sum = (r_node.sum * node.mul + node.add * (r_node.r - r_node.l + 1)) % m;

    node.add = 0;
    node.mul = 1;
    return;
}

void update_sum(ll node_idx)
{
    nodes[node_idx].sum = (nodes[left(node_idx)].sum + nodes[right(node_idx)].sum) % m;
    return;
}

void update_add(ll node_idx, ll x, ll y, ll k)
{
    tree_node &node = nodes[node_idx];
    if (x <= node.l && y >= node.r)
    {
        node.add = (node.add + k) % m;
        node.sum = (node.sum + k * (node.r - node.l + 1)) % m;
        return;
    }

    push_down(node_idx);
    ll mid = (node.r + node.l) >> 1;
    if (x <= mid)
        update_add(left(node_idx), x, y, k);
    if (y >= mid + 1)
        update_add(right(node_idx), x, y, k);
    update_sum(node_idx);
    return;
}

void update_mul(ll node_idx, ll x, ll y, ll k)
{
    tree_node &node = nodes[node_idx];
    if (x <= node.l && y >= node.r)
    {
        node.add = (node.add * k) % m;
        node.mul = (node.mul * k) % m;
        node.sum = (node.sum * k) % m;
        return;
    }

    push_down(node_idx);
    ll mid = (node.r + node.l) >> 1;
    if (x <= mid)
        update_mul(left(node_idx), x, y, k);
    if (y >= mid + 1)
        update_mul(right(node_idx), x, y, k);
    update_sum(node_idx);
    return;
}

ll query(ll node_idx, ll x, ll y)
{
    tree_node &node = nodes[node_idx];
    if (x <= node.l && y >= node.r)
        return node.sum;

    push_down(node_idx);
    ll mid = (node.r + node.l) >> 1, ans = 0;
    if (x <= mid)
        ans = (ans + query(left(node_idx), x, y)) % m;
    if (y >= mid + 1)
        ans = (ans + query(right(node_idx), x, y)) % m;
    return ans;
}

void build_tree(ll node_idx, ll l, ll r)
{
    tree_node &node = nodes[node_idx];
    node.l = l;
    node.r = r;
    node.add = 0;
    node.mul = 1;

    if (l == r)
    {
        node.sum = nums[l] % m;
        return;
    }

    ll mid = (node.r + node.l) >> 1;
    build_tree(left(node_idx), l, mid);
    build_tree(right(node_idx), mid + 1, r);
    update_sum(node_idx);
    return;
}

int main()
{
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    build_tree(1, 1, n);

    for (int i = 0; i < q; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            int k;
            cin >> k;
            update_mul(1, x, y, k);
        }
        else if (op == 2)
        {
            int k;
            cin >> k;
            update_add(1, x, y, k);
        }
        else if (op == 3)
        {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}