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
    ll E, C, F;
    Edge* dual;

    Edge() : Edge(-1, 0){}
    Edge(int E1, int C1) : E(E1), C(C1), F(0), dual(nullptr){}

    ll get_C() { return C-F; }
    void update_F(ll F1)
    {
        F += F1;
        dual->F -= F1;
    }
};

const int SIZE = 1000;
ll n, m, start, fin, cost[SIZE], u, v;
vector<Edge*> adj[SIZE];
bool visited[1000];
set<int> ans;

int main()
{
    onlycc;
    cin >> n >> m >> start >> fin;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 1; i <= n; i++)
    {
        u = i*2-1, v = i*2;
        Edge *e1 = new Edge(v, cost[i]), *e2 = new Edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u = u*2, v = v*2-1;
        Edge *e1 = new Edge(v, 1e9), *e2 = new Edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[u].push_back(e1);
        adj[v].push_back(e2);

        u -= 1, v += 1;
        e1 = new Edge(u, 1e9), e2 = new Edge(v, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[v].push_back(e1);
        adj[u].push_back(e2);
    }
    Edge *e1 = new Edge(start*2-1, 1e9), *e2 = new Edge(0, 0);
    e1->dual = e2;
    e2->dual = e1;

    adj[0].push_back(e1);
    adj[start*2-1].push_back(e2);

    e1 = new Edge(555, 1e9), e2 = new Edge(fin*2, 0);
    e1->dual = e2;
    e2->dual = e1;

    adj[fin*2].push_back(e1);
    adj[555].push_back(e2);

    start = 0;
    fin = 555;
    while(1)
    {
        int prev[SIZE];
        memset(prev, -1, sizeof(prev));
        Edge *path[SIZE];
        queue<int> q;

        q.push(start);
        while(!q.empty() && prev[fin] == -1)
        {
            int now = q.front();
            q.pop();

            for(auto e : adj[now])
            {
                int next = e->E;
                if(e->get_C() > 0 && prev[next] == -1)
                {
                    q.push(next);
                    prev[next] = now;
                    path[next] = e;
                    if(next == fin) break;
                }
            }
        }
        if(prev[fin] == -1) break;

        ll flow = 1e9;
        for(int i = fin; i != start; i = prev[i]) flow = min(flow, path[i]->get_C());
        for(int i = fin; i != start; i = prev[i]) path[i]->update_F(flow);
    }

    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if(now == 555) break;

        for(auto e : adj[now])
        {
            int next = e->E;
            if(e->get_C() > 0 && !visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++) if(visited[i*2-1] && !visited[i*2]) ans.insert(i);
    for(auto x : ans) cout << x << ' ';

    return 0;
}
