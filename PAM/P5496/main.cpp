#include <bits/stdc++.h>
#define ll long long
#define MXN 500005
using namespace std;

ll next_idx = 1, n = 0;
char str[MXN];
array<array<ll, 26>, MXN> trie;
array<ll, MXN> len;
array<ll, MXN> num;
array<ll, MXN> fail;

ll get_fail(ll idx, ll iter)    // 两个作用：既确认新节点挂哪儿，也确定新节点的fail指向哪儿
{
    while (iter - len[idx] - 1 < 0 || str[iter - len[idx] - 1] != str[iter])
        idx = fail[idx];
    return idx;
}

int main()
{
    scanf("%s", str);
    n = strlen(str);
    fail[0] = 1;
    len[1] = -1;
    ll last = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= 1)
            str[i] = (str[i] + last - 97) % 26 + 97;
        int idx = get_fail(cur, i); 
        int c = str[i] - 'a';
        if (!trie[idx][c])
        {
            next_idx++;
            fail[next_idx] = trie[get_fail(fail[idx], i)][c];
            trie[idx][c] = next_idx;
            len[next_idx] = len[idx] + 2;
            num[next_idx] = num[fail[next_idx]] + 1;
        }
        cur = trie[idx][c];
        last = num[cur];
        cout << last << ' ';
    }
    return 0;
}