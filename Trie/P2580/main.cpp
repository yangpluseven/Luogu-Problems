#include <bits/stdc++.h>
#define ll long long
#define MXN 500005
#define MXM 100005
using namespace std;

ll n, m, next_idx = 1;
array<array<ll, 27>, MXN> trie;
array<bool, MXN> last;
array<bool, MXN> vis;

void insert(string word)
{
    int idx = 0;
    for (const auto &c : word)
    {
        int i = c - 'a';
        if (trie[idx][i] == 0)
        {
            trie[idx][i] = next_idx;
            next_idx++;
        }
        idx = trie[idx][i];
    }
    last[idx] = true;
}

ll query(string word)
{
    int idx = 0;
    for (const auto &c : word)
    {
        int i = c - 'a';
        if (trie[idx][i] == 0)
        {
            return -1;
        }
        idx = trie[idx][i];
    }
    if (!last[idx])
    {
        return -1;
    }
    return idx;
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        insert(tmp);
    }
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        ll res = query(tmp);
        if (res == -1)
        {
            cout << "WRONG" << '\n';
        }
        else if (vis[res])
        {
            cout << "REPEAT" << '\n';
        }
        else
        {
            cout << "OK" << '\n';
            vis[res] = true;
        }
    }
    return 0;
}