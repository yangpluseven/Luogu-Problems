#include <bits/stdc++.h>
#define MXT 1005
#define MXM 105
using namespace std;

int t, m, times[MXM], profits[MXM], dp[MXM][MXT];

int main()
{
    ios::sync_with_stdio(0);
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> times[i];
        cin >> profits[i];
    }
    
    int max_profit = 0;
    for (int i = 1; i <= m; i++)
        for (int j = t; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - times[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - times[i]] + profits[i]);
            max_profit = max(max_profit, dp[i][j]);
        }
        
    cout << max_profit;
    return 0;
}