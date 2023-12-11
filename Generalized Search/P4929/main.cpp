// DLX
#include <bits/stdc++.h>
#define MXN 510
using namespace std;

struct DLXnode
{
    int row, col;
    int right, left, up, down;
} nodes[MXN * MXN];

int n, m, next_idx = 0;
int rows[MXN], ans[MXN], col_cnt[MXN];

// nodes[0] 头节点headNode, nodes[1] ~ nodes[m] 每一列的入口节点
void init()
{
    for (int i = 0; i <= m; i++)
    {
        nodes[i].row = 0;
        nodes[i].col = i + 1;
        nodes[i].left = i - 1;
        nodes[i].right = i + 1;
        nodes[i].up = i;
        nodes[i].down = i;
        col_cnt[i] = 0;
    }
    nodes[0].left = m;
    nodes[m].right = 0;
    next_idx = m + 1;
}

// 按顺序添加节点，从左上到右下，否则逻辑错误
void add_node(int r, int c)
{
    nodes[next_idx].row = r;
    nodes[next_idx].col = c;
    // 前提是该节点下方无节点
    nodes[next_idx].up = nodes[c].up;
    nodes[next_idx].down = c;
    nodes[nodes[next_idx].up].down = next_idx;
    nodes[nodes[next_idx].down].up = next_idx;
    if (!rows[r])
    {
        nodes[next_idx].left = next_idx;
        nodes[next_idx].right = next_idx;
        rows[r] = next_idx;
    }
    else
    {
        // 前提是该节点右侧无节点
        nodes[next_idx].left = nodes[rows[r]].left;
        nodes[next_idx].right = rows[r];
        nodes[nodes[next_idx].left].right = next_idx;
        nodes[nodes[next_idx].right].left = next_idx;
    }
    col_cnt[c]++;
    next_idx++;
}

void remove_all(int c)
{
    for (int i = nodes[c].down; i != c; i = nodes[i].down)
        for (int j = nodes[i].right; j != i; j = nodes[j].right)
        {
            nodes[nodes[j].down].up = nodes[j].up;
            nodes[nodes[j].up].down = nodes[j].down;
            col_cnt[nodes[j].col]--;
        }

    nodes[nodes[c].left].right = nodes[c].right;
    nodes[nodes[c].right].left = nodes[c].left;
}

void resume_all(int c)
{
    nodes[nodes[c].left].right = c;
    nodes[nodes[c].right].left = c;
    for (int i = nodes[c].down; i != c; i = nodes[i].down)
        for (int j = nodes[i].right; j != i; j = nodes[j].right)
        {
            nodes[nodes[j].up].down = j;
            nodes[nodes[j].down].up = j;
            col_cnt[nodes[j].col]++;
        }
}

// d 深度depth
bool dance(int d)
{
    if (nodes[0].right == 0)
    {
        for (int i = 1; i <= d - 1; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return true;
    }
    int c = nodes[0].right;
    for (int i = nodes[0].right; i; i = nodes[i].right)
    {
        if (col_cnt[i] < col_cnt[c])
            c = i;
    }
    remove_all(c);
    for (int i = nodes[c].down; i != c; i = nodes[i].down)
    {
        ans[d] = nodes[i].row;
        for (int j = nodes[i].right; j != i; j = nodes[j].right)
            remove_all(nodes[j].col);
        if (dance(d + 1))
            return true;
        for (int j = nodes[i].right; j != i; j = nodes[j].right)
            resume_all(nodes[j].col);
    }
    resume_all(c);
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp)
                add_node(i, j);
        }
    
    if (!dance(1))
        cout << "No Solution!\n";
    return 0;
}