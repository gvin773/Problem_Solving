#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

class Edge
{
public:
    int E, Capacity, F, Cost;
    Edge* dual;

    Edge() : Edge(-1, 0, 0){}
    Edge(int E1, int C1) : E(E1), Capacity(C1), F(0), Cost(0), dual(nullptr){}
    Edge(int E1, int C1, int C2) : E(E1), Capacity(C1), F(0), Cost(C2), dual(nullptr){}

    int get_R() { return Capacity-F; }
    void update_F(int F1)
    {
        F += F1;
        dual->F -= F1;
    }
};

const int SIZE = 2727;
ll n, a[SIZE], b[SIZE], start, fin, level[SIZE], used[SIZE], ans, arr[SIZE][SIZE];
vector<Edge*> adj[SIZE];

bool bfs()
{
    memset(level, -1, sizeof(level));
    level[start] = 0;

    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto &e : adj[now])
        {
            int next = e->E;
            if(level[next] == -1 && e->get_R() > 0)
            {
                level[next] = level[now] + 1;
                q.push(next);
            }
        }
    }

    return level[fin] != -1;
}

int dfs(int now, int target, int flow)
{
    if(now == target) return flow;

    for(auto &i = used[now]; i < adj[now].size(); i++)
    {
        auto e = adj[now][i];
        int next = e->E;

        if(level[next] == level[now]+1 && e->get_R() > 0)
        {
            int residual = dfs(next, target, min(flow, e->get_R()));
            if(residual > 0)
            {
                e->update_F(residual);
                return residual;
            }
        }
    }

    return 0;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    start = n+n+n*n, fin = n+n+n*n+1;
    for(int i = 0; i < n; i++)
    {
        Edge *e1 = new Edge(i, a[i]), *e2 = new Edge(start, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[start].push_back(e1);
        adj[i].push_back(e2);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Edge *e1 = new Edge(n+n+i*n+j, 1e9), *e2 = new Edge(i, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[i].push_back(e1);
            adj[n+n+i*n+j].push_back(e2);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Edge *e1 = new Edge(n+j, 1e9), *e2 = new Edge(n+n+i*n+j, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[n+n+i*n+j].push_back(e1);
            adj[n+j].push_back(e2);
        }
    }
    for(int i = 0; i < n; i++)
    {
        Edge *e1 = new Edge(fin, b[i]), *e2 = new Edge(n+i, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[n+i].push_back(e1);
        adj[fin].push_back(e2);
    }

    int MF = 0;
    while(bfs())
    {
        memset(used, 0, sizeof(used));
        while(1)
        {
            int flow = dfs(start, fin, 1e9);
            if(!flow) break;
            MF += flow;
        }
    }

    int lo = 0, hi = 10000;
    while(lo <= hi)
    {
        int mid = (lo+hi) / 2;

        for(int i = 0; i < n+n+n*n+2; i++)
        {
            for(auto e : adj[i])
            {
                e->F = 0;
                if(i == start || i == fin) continue;
                if(e->E == start || e->E == fin) continue;
                if(0 <= e->E && e->E < 2*n) continue;
                e->Capacity = mid;
            }
        }

        int ret = 0;
        while(bfs())
        {
            memset(used, 0, sizeof(used));
            while(1)
            {
                int flow = dfs(start, fin, 1e9);
                if(!flow) break;
                ret += flow;
            }
        }

        if(ret == MF)
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout << ans << '\n';
    for(int i = 0; i < n+n+n*n+2; i++)
    {
        for(auto e : adj[i])
        {
            e->F = 0;
            if(i == start || i == fin) continue;
            if(e->E == start || e->E == fin) continue;
            if(0 <= e->E && e->E < 2*n) continue;
            e->Capacity = ans;
        }
    }
    while(bfs())
    {
        memset(used, 0, sizeof(used));
        while(1)
        {
            int flow = dfs(start, fin, 1e9);
            if(!flow) break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(auto e : adj[i])
        {
            int j = e->E;
            if(n+n <= j && j < n+n+n*n) arr[i][(j-n-n)%n] += e->F;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
