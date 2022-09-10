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
    ll E, Capacity, F, Cost;
    Edge* dual;

    Edge() : Edge(-1, 0, 0){}
    Edge(int E1, int C1, int C2) : E(E1), Capacity(C1), F(0), Cost(C2), dual(nullptr){}

    ll get_R() { return Capacity-F; }
    void update_F(ll F1)
    {
        F += F1;
        dual->F -= F1;
    }
};

const int SIZE = 502;
ll tc, n, m, a, b, start, fin, MCMF;
vector<Edge*> adj[SIZE];
bool color[SIZE], coin[SIZE];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        for(int i = 0; i < SIZE; i++) adj[i].clear();
        MCMF= 0;
        start = 0, fin = n+1;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Edge *e1 = new Edge(b, 1e9, 1), *e2 = new Edge(a, 0, -1);
            e1->dual = e2;
            e2->dual = e1;

            adj[a].push_back(e1);
            adj[b].push_back(e2);

            e1 = new Edge(a, 1e9, 1), e2 = new Edge(b, 0, -1);
            e1->dual = e2;
            e2->dual = e1;

            adj[b].push_back(e1);
            adj[a].push_back(e2);
        }
        for(int i = 1; i <= n; i++) cin >> color[i];
        for(int i = 1; i <= n; i++) cin >> coin[i];
        for(int i = 1; i <= n; i++)
        {
            if(!coin[i])
            {
                Edge *e1 = new Edge(i, 1, 0), *e2 = new Edge(start, 0, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[start].push_back(e1);
                adj[i].push_back(e2);
            }
            if(!color[i])
            {
                Edge *e1 = new Edge(fin, 1, 0), *e2 = new Edge(i, 0, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[i].push_back(e1);
                adj[fin].push_back(e2);
            }
        }

        while(1)
        {
            int prev[SIZE], dist[SIZE];
            memset(prev, -1, sizeof(prev));
            fill(dist, dist+SIZE, 1e9);
            Edge *path[SIZE];
            queue<int> q;
            bool inq[SIZE] = {};

            q.push(start);
            dist[start] = 0;
            inq[start] = true;
            while(!q.empty())
            {
                int now = q.front();
                q.pop();
                inq[now] = false;

                for(auto ee : adj[now])
                {
                    int next = ee->E;
                    if(ee->get_R() > 0 && dist[next] > dist[now] + ee->Cost)
                    {
                        dist[next] = dist[now] + ee->Cost;
                        prev[next] = now;
                        path[next] = ee;

                        if(!inq[next])
                        {
                            q.push(next);
                            inq[next] = true;
                        }
                    }
                }
            }
            if(prev[fin] == -1) break;

            ll flow = 1e9;
            for(int i = fin; i != start; i = prev[i]) flow = min(flow, path[i]->get_R());
            for(int i = fin; i != start; i = prev[i])
            {
                MCMF += flow * path[i]->Cost;
                path[i]->update_F(flow);
            }
        }

        cout << MCMF << '\n';
    }

    return 0;
}
