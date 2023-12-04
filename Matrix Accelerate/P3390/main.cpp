#include <bits/stdc++.h>
#define ll long long
#define MXN 105
#define MOD 1000000007
using namespace std;

ll n, k, base[MXN][MXN], ans[MXN][MXN], tmp[MXN][MXN];

void build_identity_matrix()
{
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 1;
    }
}

void ans_times_mat()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                tmp[i][j] = (tmp[i][j] + ans[i][k] * base[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = tmp[i][j];
            tmp[i][j] = 0;
        }
    }
    return;
}

void mat_times_mat()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                tmp[i][j] = (tmp[i][j] + base[i][k] * base[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            base[i][j] = tmp[i][j];
            tmp[i][j] = 0;
        }
    }
    return;
}

void matrix_fast_pow()
{
    while (k > 0)
    {
        if (k & 1)
        {
            ans_times_mat();
        }
        mat_times_mat();
        k >>= 1;
    }
    return;
}

int main()
{
    cin >> n >> k;
    memset(ans, 0, n * sizeof(ans[0]));
    build_identity_matrix();
    for (register int i = 0; i < n; i++)
    {
        for (register int j = 0; j < n; j++)
        {
            cin >> base[i][j];
        }
    }
    matrix_fast_pow();
    for (register int i = 0; i < n; i++)
    {
        for (register int j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}