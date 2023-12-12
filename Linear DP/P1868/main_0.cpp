// dpxy
#include <bits/stdc++.h>
#define MXN 3000005
using namespace std;

int n;
int len[MXN], right_bound[MXN], dp[MXN];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int max_right = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        len[x] = y - x + 1;
        right_bound[x] = y;
        max_right = max(max_right, y);
    }
    for (int i = max_right; i; i--)
    {
        if (len[i])
        {
            dp[i] = max(dp[i + 1], dp[right_bound[i] + 1] + len[i]);
        }
        else
            dp[i] = dp[i + 1];
    }
    
    cout << dp[1];
    return 0;
}