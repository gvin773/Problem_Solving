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
    int E, C, F;
    Edge* dual;

    Edge() : Edge(-1, 0){}
    Edge(int E1, int C1) : E(E1), C(C1), F(0), dual(nullptr){}

    int get_C() { return C-F; }
    void update_F(ll F1)
    {
        F += F1;
        dual->F -= F1;
    }
};

ll n, p, u, v, flow, ans;
vector<Edge*> adj[888];

int main()
{
    onlycc;
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
    {
        Edge *e1 = new Edge(i*2-1, 1), *e2 = new Edge(i*2-2, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[i*2-2].push_back(e1);
        adj[i*2-1].push_back(e2);
    }
    for(int i = 0; i < p; i++)
    {
        cin >> u >> v;
        Edge *e1 = new Edge(v*2-2, 1), *e2 = new Edge(u*2-1, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[u*2-1].push_back(e1);
        adj[v*2-2].push_back(e2);

        Edge *e3 = new Edge(u*2-2, 1), *e4 = new Edge(v*2-1, 0);
        e3->dual = e4;
        e4->dual = e3;

        adj[v*2-1].push_back(e3);
        adj[u*2-2].push_back(e4);
    }

    while(1)
    {
        int prev[888];
        memset(prev, -1, sizeof(prev));
        Edge *path[888];
        queue<int> q;

        q.push(1);
        while(!q.empty() && prev[2] == -1)
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
                    if(next == 2) break;
                }
            }
        }
        if(prev[2] == -1) break;

        int flow = 1e9;
        for(int i = 2; i != 1; i = prev[i]) flow = min(flow, path[i]->get_C());
        for(int i = 2; i != 1; i = prev[i]) path[i]->update_F(flow);
        ans += flow;
    }
    cout << ans;

    return 0;
}
