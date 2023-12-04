#include <bits/stdc++.h>
#define ll long long
#define MXN 200005
using namespace std;

ll n, next_idx = 1;
array<array<ll, 27>, MXN> trie;
array<ll, MXN> indeg;
array<ll, MXN> fail;
array<ll, MXN> ans;       // times of visited a pattern in query()
array<ll, MXN> vis;       // real times of visited a pattern after topu()
array<ll, MXN> trie_vis;  // form trie node to vis
array<ll, MXN> input_vis; // from input idx to vis
string str;

void insert(string word, ll in_idx)
{
    int tr_idx = 1;
    for (const auto &c : word)
    {
        int i = c - 'a';
        if (trie[tr_idx][i] == 0)
        {
            next_idx++;
            trie[tr_idx][i] = next_idx;
        }
        tr_idx = trie[tr_idx][i];
    }
    if (!trie_vis[tr_idx])
    {
        trie_vis[tr_idx] = in_idx;
    }
    input_vis[in_idx] = trie_vis[tr_idx];
}

void build()
{
    for (int i = 0; i < 26; i++)
    {
        trie[0][i] = 1;
    }
    queue<ll> q;
    q.push(1);
    fail[1] = 0;
    while (!q.empty())
    {
        ll tr_idx = q.front();
        q.pop();
        ll cur_fail = fail[tr_idx];
        for (int i = 0; i < 26; i++)
        {
            if (trie[tr_idx][i])
            {
                fail[trie[tr_idx][i]] = trie[cur_fail][i];
                indeg[trie[cur_fail][i]]++;
                q.push(trie[tr_idx][i]);
            }
            else
            {
                trie[tr_idx][i] = trie[cur_fail][i];
            }
        }
    }
}

void query(string word)
{
    int tr_idx = 1;
    for (const auto &c : word)
    {
        int i = c - 'a';
        tr_idx = trie[tr_idx][i];
        ans[tr_idx]++;
    }
}

void topu()
{
    queue<ll> q;
    for (int i = 0; i <= next_idx; i++)
    {
        if (!indeg[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int tr_idx = q.front();
        q.pop();
        vis[trie_vis[tr_idx]] = ans[tr_idx];
        int cur_fail = fail[tr_idx];
        ans[cur_fail] += ans[tr_idx];
        indeg[cur_fail]--;
        if (!indeg[cur_fail])
        {
            q.push(cur_fail);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        insert(tmp, i);
    }
    build();
    cin >> str;
    query(str);
    topu();
    for (int i = 1; i <= n; i++)
    {
        cout << vis[input_vis[i]] << '\n';
    }
    return 0;
}