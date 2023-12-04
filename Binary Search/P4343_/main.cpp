#include <bits/stdc++.h>
#define ll long long
#define MXN 100005
using namespace std;

ll n, k, lines[MXN];

int simulate(ll max_lines)
{
    ll sum = 0, ac = 0;
    for (int i = 0; i < n; i++)
    {
        sum += lines[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum >= max_lines)
        {
            sum = 0;
            ac++;
        }
    }
    if (ac > k)
    {
        return 1;
    }
    if (ac < k)
    {
        return -1;
    }
    return 0;
}

int main()
{
    cin >> n >> k;
    ll sum = 0, lbound = 0, rbound = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i];
        if (lines[i] > 0)
        {
            sum += lines[i];
        }
    }

    ll l = 1, r = sum, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        int res = simulate(mid);
        if (res > 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    if (simulate(l) > 0)
    {
        l++;
    }
    else if (simulate(l) < 0)
    {
        l--;
    }
    lbound = l;
    if (l >= sum || simulate(l) != 0)
    {
        cout << -1;
        return 0;
    }

    l = 1, r = sum;
    while (l < r)
    {
        mid = (l + r) / 2;
        int res = simulate(mid);
        if (res < 0)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (simulate(l) < 0)
    {
        l--;
    }
    else if (simulate(l) > 0)
    {
        l++;
    }
    rbound = l;
    if (l <= 0 || simulate(l) != 0)
    {
        cout << -1;
        return 0;
    }
    cout << lbound << ' ' << rbound;
    return 0;
}