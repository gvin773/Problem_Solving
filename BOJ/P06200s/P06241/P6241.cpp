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

const int SIZE = 505;
ll n, f, d, dish, drink, fi, di, start, fin, level[SIZE], used[SIZE];
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
    cin >> n >> f >> d;
    for(int i = 0; i < n; i++)
    {
        Edge *e1 = new Edge(i*2+1, 1), *e2 = new Edge(i*2, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[i*2].push_back(e1);
        adj[i*2+1].push_back(e2);
    }
    start = n*2;
    for(int i = 1; i <= f; i++)
    {
        Edge *e1 = new Edge(n*2+i, 1), *e2 = new Edge(start, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[start].push_back(e1);
        adj[n*2+i].push_back(e2);
    }
    fin = n*2+f+d+1;
    for(int i = 1; i <= d; i++)
    {
        Edge *e1 = new Edge(fin, 1), *e2 = new Edge(n*2+f+i, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[n*2+f+i].push_back(e1);
        adj[fin].push_back(e2);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> dish >> drink;
        for(int j = 0; j < dish; j++)
        {
            cin >> fi;
            Edge *e1 = new Edge(i*2, 1), *e2 = new Edge(n*2+fi, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[n*2+fi].push_back(e1);
            adj[i*2].push_back(e2);
        }
        for(int j = 0; j < drink; j++)
        {
            cin >> di;
            Edge *e1 = new Edge(n*2+f+di, 1), *e2 = new Edge(i*2+1, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[i*2+1].push_back(e1);
            adj[n*2+f+di].push_back(e2);
        }
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
    cout << MF;

    return 0;
}
