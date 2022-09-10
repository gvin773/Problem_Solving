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

ll n, m, u, v, start, fin, flow, ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<Edge*> adj[101101];
string city[100];
bool K, H;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> city[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(city[i][j] == 'K') K = true;
            if(city[i][j] == 'H') H = true;
        }
    }
    if((K^H) || (!K && !H))
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(city[i][j] == 'K')
            {
                for(int z = 0; z < 4; z++)
                {
                    int nx = i+dx[z], ny = j+dy[z];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m && city[nx][ny] == 'H')
                    {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            u = (i*m+j)*2, v = (i*m+j)*2+1;
            Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[u].push_back(e1);
            adj[v].push_back(e2);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(city[i][j] == '#') continue;
            for(int z = 0; z < 4; z++)
            {
                int nx = i+dx[z], ny = j+dy[z];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || city[nx][ny] == '#') continue;

                u = (i*m+j)*2+1, v = (nx*m+ny)*2;
                Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[u].push_back(e1);
                adj[v].push_back(e2);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(city[i][j] == 'K') start = (i*m+j)*2+1;
            if(city[i][j] == 'H') fin = (i*m+j)*2;
        }
    }
    while(1)
    {
        int prev[101101];
        memset(prev, -1, sizeof(prev));
        Edge *path[101101];
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

        int flow = 1e9;
        for(int i = fin; i != start; i = prev[i]) flow = min(flow, path[i]->get_C());
        for(int i = fin; i != start; i = prev[i]) path[i]->update_F(flow);
        ans += flow;
    }
    cout << ans;

    return 0;
}
