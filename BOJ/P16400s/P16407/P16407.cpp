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

ll n, m, c, cost[30], start, fin, u, v, ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<Edge*> adj[10101];
string city[100];

int main()
{
    onlycc;
    start = 3001, fin = 3002;
    cin >> n >> m >> c;
    for(int i = 0; i < m; i++) cin >> city[i];
    for(int i = 0; i < c; i++) cin >> cost[i];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(city[i][j] == 'B')
            {
                u = start, v = (i*30+j)*2;
                Edge *e1 = new Edge(v, 1e9), *e2 = new Edge(u, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[u].push_back(e1);
                adj[v].push_back(e2);

                if(i == 0 || j == 0 || i == m-1 || j == n-1)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            u = (i*30+j)*2, v = (i*30+j)*2+1;
            Edge *e1 = new Edge(v, (city[i][j] == '.' || city[i][j] == 'B') ? 1e9: cost[city[i][j]-'a']), *e2 = new Edge(u, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[u].push_back(e1);
            adj[v].push_back(e2);
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int z = 0; z < 4; z++)
            {
                int nx = i+dx[z], ny = j+dy[z];

                u = (i*30+j)*2+1, v = (nx*30+ny)*2;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) v = fin;
                Edge *e1 = new Edge(v, 1e9), *e2 = new Edge(u, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[u].push_back(e1);
                adj[v].push_back(e2);
            }
        }
    }

    while(1)
    {
        int prev[10101];
        memset(prev, -1, sizeof(prev));
        Edge *path[10101];
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
    cout << (ans >= 1e9 ? -1 : ans);

    return 0;
}
