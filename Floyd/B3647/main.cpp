#include <bits/stdc++.h>
#define ll long long
#define MXN 105
#define MXM 4505
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n, m;
array<array<ll, MXN>, MXN> dp;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dp[i].fill(INF);
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = w;
        dp[v][u] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}