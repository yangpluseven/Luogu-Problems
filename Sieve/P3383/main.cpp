#include <bits/stdc++.h>
#define MXN 100000005
#define MXP 5800000
#define MXQ 1000005
using namespace std;

int n, q, next_idx = 0;
array<bool, MXN> is_prime;
array<int, MXP> prime;

void build()
{
    is_prime.fill(true);
    is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[next_idx] = i;
            next_idx++;
        }
        for (int j = 0; j < next_idx && i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> q;
    build();
    for (int i = 0; i < q; i++)
    {
        int query = 0;
        cin >> query;
        cout << prime[query - 1] << '\n';
    }
    return 0;
}