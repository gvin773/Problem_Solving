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

const int SIZE = 333;
ll n, start, fin, MCMF, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<Edge*> adj[SIZE];
string tofu[SIZE];

int get_cost(char x, char y)
{
    if(x == 'A' && y == 'A') return 100;
    if((x == 'A' && y == 'B') || (x == 'B' && y == 'A')) return 70;
    if((x == 'A' && y == 'C') || (x == 'C' && y == 'A')) return 40;
    if(x == 'B' && y == 'B') return 50;
    if((x == 'B' && y == 'C') || (x == 'C' && y == 'B')) return 30;
    if(x == 'C' && y == 'C') return 20;
    return 0;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> tofu[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i+j)&1)
            {
                for(int z = 0; z < 4; z++)
                {
                    int nx = i+dx[z], ny = j+dy[z];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    int cost = get_cost(tofu[i][j], tofu[nx][ny]);
                    Edge *e1 = new Edge(nx*n+ny, 1, -cost), *e2 = new Edge(i*n+j, 0, cost);
                    e1->dual = e2;
                    e2->dual = e1;

                    adj[i*n+j].push_back(e1);
                    adj[nx*n+ny].push_back(e2);
                }
            }
        }
    }
    start = n*n, fin = n*n+1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i+j)&1)
            {
                Edge *e1 = new Edge(i*n+j, 1, 0), *e2 = new Edge(start, 0, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[start].push_back(e1);
                adj[i*n+j].push_back(e2);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Edge *e1 = new Edge(fin, 1, 0), *e2 = new Edge(i*n+j, 0, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[i*n+j].push_back(e1);
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

            for(auto e : adj[now])
            {
                int next = e->E;
                if(e->get_R() > 0 && dist[next] > dist[now] + e->Cost)
                {
                    dist[next] = dist[now] + e->Cost;
                    prev[next] = now;
                    path[next] = e;

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
    cout << -MCMF;

    return 0;
}
