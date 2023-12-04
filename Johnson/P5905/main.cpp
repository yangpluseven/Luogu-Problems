#include <bits/stdc++.h>
#define ll long long
#define MXN 5005
#define MXM 10005
#define INF 1e9     // why cant we use 1000000000? strange things.
using namespace std;

struct Edge
{
    int to, dis, next;  // dis相当于w
};

struct Node
{
    int dis;
    int idx;
    Node(int dis_, int idx_) : dis(dis_), idx(idx_) {}
    bool operator<(const Node &n) const
    {
        return n.dis < dis;
    }
};

array<Edge, MXM> edges;
array<int, MXN> head, t;
array<ll, MXN> dis, h;
array<bool, MXN> vis;
int next_idx = 0, n, m;;

inline void add_edge(int u, int v, int d) // 链式前向星
{
    next_idx++;
    edges[next_idx].dis = d;
    edges[next_idx].to = v;
    edges[next_idx].next = head[u];
    head[u] = next_idx;
}

void dijkstra(int s)
{
    priority_queue<Node> q;
    for (register int i = 1; i <= n; i++)
        dis[i] = INF;
    vis.fill(false);
    dis[s] = 0;
    q.push(Node(0, s));
    while (!q.empty())
    {
        Node node = q.top();
        q.pop();
        int u = node.idx, d = node.dis;
        if (vis[u])
            continue;
        vis[u] = true;
        for (register int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (dis[v] > dis[u] + edges[i].dis)
            {
                dis[v] = dis[u] + edges[i].dis;
                if (!vis[v])
                {
                    q.push(Node(dis[v], v));
                }
            }
        }
    }
}

bool spfa(int s)
{
    queue<int> q;
    h.fill(0x3f3f3f3f3f3f3f3f);
    h[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (h[v] > h[u] + edges[i].dis)
            {
                h[v] = h[u] + edges[i].dis;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                    t[v]++;
                    if (t[v] == n + 1)
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (register int i = 0; i < m; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add_edge(u, v, d);
    }

    for (int i = 1; i <= n; i++)
        add_edge(0, i, 0);
    
    if (!spfa(0))
    {
        cout << -1 << endl;
        return 0;
    }

    for (int u = 1; u <= n; u++)
        for (int i = head[u]; i; i = edges[i].next)
            edges[i].dis += h[u] - h[edges[i].to];
    
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        ll ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] == INF)
                ans += j * INF;
            else
                ans += j * (dis[j] + h[j] - h[i]);
        }
        cout << ans << endl;
    }
    return 0;
}