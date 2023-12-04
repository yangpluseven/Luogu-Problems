#include <bits/stdc++.h>
#define ull unsigned long long
#define BASE 233
#define MXN 100005
#define MXM 1505
using namespace std;

ull n, hashs[MXN];
char s[MXM];

ull my_hash(char str[])
{
    ull code = 0, len = strlen(str);;
    for (int i = 0; i < len; i++)
    {
        code = code * BASE + (ull)str[i];
    }
    return code;
}

int main()
{
    int ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        hashs[i] = my_hash(s);
    }
    sort(hashs, hashs + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (hashs[i] != hashs[i + 1])
            ans++;
    }
    cout << ans;
    return 0;
}