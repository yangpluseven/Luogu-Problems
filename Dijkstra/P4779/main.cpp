#include <bits/stdc++.h>
#define MXN 100005
#define MXM 500010
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int to, dis, next;
};

struct Node
{
    int dis;
    int idx;
    Node(int dis_, int pos_) : dis(dis_), idx(pos_) {}
    bool operator<(const Node &n) const
    {
        return n.dis < dis;
    }
};

array<Edge, MXM> edges;
array<int, MXN> head, dis;
array<bool, MXN> vis;
int next_idx = 0;
int n, m, s;

inline void add_edge(int u, int v, int d) // 链式前向星
{
    next_idx++;
    edges[next_idx].dis = d;
    edges[next_idx].to = v;
    edges[next_idx].next = head[u];
    head[u] = next_idx;
}

priority_queue<Node> q;

void dijkstra()
{
    dis[s] = 0;
    q.push(Node(0, s));
    while (!q.empty())
    {
        Node node = q.top();
        q.pop();
        int x = node.idx, d = node.dis;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; i; i = edges[i].next)
        {
            int y = edges[i].to;
            if (dis[y] > dis[x] + edges[i].dis)
            {
                dis[y] = dis[x] + edges[i].dis;
                if (!vis[y])
                {
                    q.push(Node(dis[y], y));
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        dis[i] = INF;
    for (register int i = 0; i < m; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add_edge(u, v, d);
    }
    dijkstra();
    for (register int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}