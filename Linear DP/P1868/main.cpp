// Didn't pass.
#include <bits/stdc++.h>
#define ll long long
#define MXN 150005
using namespace std;

struct Area
{
    ll lb, rb, len, maxl;
    bool operator<(Area area)
    {
        return this->rb < area.rb;
    }
} areas[MXN];

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> areas[i].lb;
        cin >> areas[i].rb;
        areas[i].len = areas[i].rb - areas[i].lb + 1;
        areas[i].maxl = 0;
    }

    sort(areas, areas + n);
    ll dp[n], max_len = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = areas[i].len;
        for (int j = i - 1; j >= 0; j--)
        {
            if (areas[i].lb > areas[j].rb)
            {
                dp[i] = max(dp[i], areas[j].maxl + areas[i].len);
                break;
            }
        }
        max_len = max(max_len, dp[i]);
        areas[i].maxl = max_len;
    }

    cout << max_len;
    return 0;
}