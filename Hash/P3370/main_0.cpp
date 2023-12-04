#include <bits/stdc++.h>
#define ull unsigned long long
#define BASE 233
#define MXN 100005
using namespace std;

ull n, hashs[MXN];

int main()
{
    int ans = 1;
    cin >> n;
    set<string> strs;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strs.insert(str);
    }
    cout << strs.size();
    return 0;
}