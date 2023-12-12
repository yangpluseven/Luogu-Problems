// LIS Longest Increasing Subsequence
#include <bits/stdc++.h>
#define MXN 105
using namespace std;

int n;
int arr[MXN];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lis[MXN], lds[MXN];
    memset(lis, 0, sizeof(lis));
    memset(lds, 0, sizeof(lds));

    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    lds[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; i++)
        max_len = max(lis[i] + lds[i] - 1, max_len);

    cout << n - max_len;
    return 0;
}