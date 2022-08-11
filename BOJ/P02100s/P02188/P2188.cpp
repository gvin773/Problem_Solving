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

ll n, m, s, v, flow, ans;
vector<Edge*> adj[777];

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        Edge *e1 = new Edge(i, 1), *e2 = new Edge(0, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[0].push_back(e1);
        adj[i].push_back(e2);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 0; j < s; j++)
        {
            cin >> v;
            v += 200;
            Edge *e1 = new Edge(v, 1), *e2 = new Edge(i, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[i].push_back(e1);
            adj[v].push_back(e2);
        }
    }
    for(int i = 201; i <= 400; i++)
    {
        Edge *e1 = new Edge(401, 1), *e2 = new Edge(i, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[i].push_back(e1);
        adj[401].push_back(e2);
    }

    while(1)
    {
        int prev[777];
        memset(prev, -1, sizeof(prev));
        Edge *path[777];
        queue<int> q;

        q.push(0);
        while(!q.empty() && prev[401] == -1)
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
                    if(next == 401) break;
                }
            }
        }
        if(prev[401] == -1) break;

        int flow = 1e9;
        for(int i = 401; i != 0; i = prev[i]) flow = min(flow, path[i]->get_C());
        for(int i = 401; i != 0; i = prev[i]) path[i]->update_F(flow);
        ans += flow;
    }
    cout << ans;

    return 0;
}
