#include <bits/stdc++.h>
#define ll long long
#define MXN 105
using namespace std;

int r, c, movement[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll grid[MXN][MXN], vis[MXN][MXN];

ll max_length(int row, int col)
{
    ll res = 1;
    if (vis[row][col] != 0)
    {
        return vis[row][col];
    }
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + movement[i][0], ncol = col + movement[i][1];
        if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && grid[nrow][ncol] < grid[row][col])
        {
            res = max(max_length(nrow, ncol) + 1, res);
        }
    }
    vis[row][col] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> r >> c;
    ll max_len = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
        
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            max_len = max(max_length(i, j), max_len);

    cout << max_len;
}