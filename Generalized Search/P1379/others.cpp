#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
ll n;
int main()
{
    cin >> n;
    queue<ll> q;
    q.push(n);
    map<ll, ll> m;
    m[n] = 0;
    while (!q.empty())
    {
        int u = q.front();
        int c[3][3], f = 0, g = 0, n = u;
        q.pop();
        if (u == 123804765)
            break;
        for (ll i = 2; i >= 0; i--)
            for (ll j = 2; j >= 0; j--)
            {
                c[i][j] = n % 10, n /= 10;
                if (!c[i][j])
                    f = i, g = j;
            }
        for (ll i = 0; i < 4; i++)
        {
            ll nx = f + dx[i], ny = g + dy[i], ns = 0;
            if (nx < 0 || ny < 0 || nx > 2 || ny > 2)
                continue;
            swap(c[nx][ny], c[f][g]);
            for (ll i = 0; i < 3; i++)
                for (ll j = 0; j < 3; j++)
                    ns = ns * 10 + c[i][j];
            if (!m.count(ns))
            {
                m[ns] = m[u] + 1;
                q.push(ns);
            }
            swap(c[nx][ny], c[f][g]);
        }
    }
    cout << m[123804765] << endl;
    return 0;
}
