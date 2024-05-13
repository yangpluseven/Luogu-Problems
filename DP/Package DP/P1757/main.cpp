#include <bits/stdc++.h>
#define MAXN 1005
#define MAXK 105
using namespace std;

vector<vector<vector<int>>> objects(MAXK);
vector<vector<int>> dp;
int m, n;

int main()
{
    int gMax = 0, vMax = 0;
    ios::sync_with_stdio(0);
    cin >> m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, v, g;
        cin >> w;
        cin >> v;
        cin >> g;
        vector<int> vec = {w, v};
        objects[g].push_back(vec);
        gMax = max(gMax, g);
    }
    dp = vector<vector<int>>(gMax + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= gMax; i++)
    {
        for (int j = 0; j < objects[i].size(); j++)
        {
            for (int k = m; k >= objects[i][j][0]; k--)
            {
                dp[i][k] = max(dp[i][k], max(dp[i - 1][k], dp[i - 1][k - objects[i][j][0]] + objects[i][j][1]));
                vMax = max(vMax, dp[i][k]);
            }
        }
    }
    cout << vMax;
    return 0;
}