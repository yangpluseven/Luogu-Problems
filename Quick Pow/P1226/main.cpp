#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fast_pow(ll a, ll b, ll p)
{
    ll base = a, res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= base;
            res %= p;
        }
        base *= base;
        base %= p;
        b >>= 1;
    }
    return res;
}

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    ll ans = fast_pow(a, b, p);
    cout << a << '^' << b << " mod " << p << '=' << ans;
    return 0;
}