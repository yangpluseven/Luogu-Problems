#include <bits/stdc++.h>
#define MXN 35
using namespace std;

int n, grid[MXN][MXN];
bool vis[MXN][MXN];
int movement[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool has_breakout(int row, int col) // Has breakout or not
{
    if (row < 0 || row >= n || col < 0 || col >= n)
        return true;
    if (vis[row][col] || grid[row][col] == 1)
        return false;
    vis[row][col] = true;
    bool res = false;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + movement[i][0], ncol = col + movement[i][1];
        if (has_breakout(nrow, ncol))
        {
            res = true;
        }
    }
    return res;
}

void fill(int row, int col)
{
    if (row < 0 || row >= n || col < 0 || col >= n)
        return;
    if (!vis[row][col] || grid[row][col] == 2)
        return;
    grid[row][col] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + movement[i][0], ncol = col + movement[i][1];
        fill(nrow, ncol);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[i][j] && grid[i][j] == 0)
                if (!has_breakout(i, j))
                    fill(i, j);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}