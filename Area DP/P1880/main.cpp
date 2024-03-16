#include <bits/stdc++.h>
#define MXN 105
#define INF 0x3f3f3f3f
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    vector<vector<int>> max_dp(n * 2, vector<int>(n * 2, 0));
    vector<vector<int>> min_dp(n * 2, vector<int>(n * 2, INF));
    vector<int> arr(n * 2, 0);
    for (int i = 1; i < 2 * n; i++)
    {
        if (i <= n)
            cin >> arr[i];
        else
            arr[i] = arr[i - n];
        min_dp[i][i] = 0;
    }
    for (int i = 1; i < 2 * n; i++)
        arr[i] += arr[i - 1];

    for (int k = 2; k <= n; k++)
    {
        for (int i = 1; i <= 2 * n - k; i++)
        {
            int sum = arr[i + k - 1] - arr[i - 1];
            for (int j = 0; j < k - 1; j++)
            {
                max_dp[i][i + k - 1] = std::max(max_dp[i][i + j] + max_dp[i + j + 1][i + k - 1] + sum, max_dp[i][i + k - 1]);
                min_dp[i][i + k - 1] = std::min(min_dp[i][i + j] + min_dp[i + j + 1][i + k - 1] + sum, min_dp[i][i + k - 1]);
            }
        }
    }
    int max = 0, min = INF;
    for (int i = 1; i <= n; i++)
    {
        max = std::max(max, max_dp[i][i + n - 1]);
        min = std::min(min, min_dp[i][i + n - 1]);
    }
    cout << min << endl;
    cout << max << endl;
    return 0;
}