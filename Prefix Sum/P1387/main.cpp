#include <bits/stdc++.h>
#define MXN 105
using namespace std;

int mat[MXN][MXN];
int m, n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mat[i][j] += mat[i][j - 1];

    for (int j = 0; j <= m; j++)
        for (int i = 1; i <= n; i++)
            mat[i][j] += mat[i - 1][j];

    int max_len = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 1; i + k < n && j + k < m; k++)
            {
                int ul = mat[i][j], ur = mat[i][j + k], dl = mat[i + k][j], dr = mat[i + k][j + k];
                int area = dr - ur - dl + ul;
                if (area == k * k && k > max_len)
                    max_len = k;
            }
    
    cout << max_len;
    return 0;
}