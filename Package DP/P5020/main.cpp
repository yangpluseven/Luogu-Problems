#include <bits/stdc++.h>
#define MXA 25005
#define MXN 105
using namespace std;

int n, t, ans;
int dp[MXA], arr[MXN];


int main()
{
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        ans = n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        sort(arr + 1, arr + n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dp[arr[i]])
            {
                ans--;
                continue;
            }
            for (int j = arr[i]; j <= arr[n]; j++)
            {
                dp[j] = dp[j] | dp[j - arr[i]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}