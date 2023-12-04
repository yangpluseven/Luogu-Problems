#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll t, query;
void matrix_times(ll mul[3][3], ll res[3][3])
{
    ll tmp[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                tmp[i][j] = (tmp[i][j] + mul[i][k] * res[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = tmp[i][j];
        }
    }
    return;
}

void fast_pow(ll base[3][3], ll ans[3][3], ll k)
{
    while (k > 0)
    {
        if (k & 1)
        {
            matrix_times(base, ans);
        }
        matrix_times(base, base);
        k >>= 1;
    }
    return;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> query;
        if (query <= 3)
        {
            cout << 1 << endl;
            continue;
        }

        ll base[3][3] = {{1, 0, 1}, {1, 0, 0}, {0, 1, 0}};
        ll ans[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        fast_pow(base, ans, query - 3);
        ll sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum = (sum + ans[0][i]) % MOD;
        }
        cout << sum << endl;
    }
    return 0;
}