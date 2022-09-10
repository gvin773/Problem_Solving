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

const int SIZE = 200002;
ll r, c, cost[500][500], cx, cy, start, fin, u, v, ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<Edge*> adj[SIZE];

int main()
{
    onlycc;
    start = 200000, fin = 200001;
    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] == 0) continue;

            u = (i*c+j)*2, v = (i*c+j)*2+1;
            Edge *e1 = new Edge(v, cost[i][j]), *e2 = new Edge(u, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[u].push_back(e1);
            adj[v].push_back(e2);
        }
    }
    cin >> cx >> cy;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            for(int z = 0; z < 4; z++)
            {
                int nx = i+dx[z], ny = j+dy[z];

                u = (i*c+j)*2+1, v = (nx*c+ny)*2;
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) v = fin;
                Edge *e1 = new Edge(v, 1e9), *e2 = new Edge(u, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[u].push_back(e1);
                adj[v].push_back(e2);
            }
        }
    }
    Edge *e1 = new Edge((cx*c+cy)*2, 1e9), *e2 = new Edge(start, 0);
    e1->dual = e2;
    e2->dual = e1;

    adj[start].push_back(e1);
    adj[(cx*c+cy)*2].push_back(e2);

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
        ans += flow;
    }
    cout << ans;

    return 0;
}
