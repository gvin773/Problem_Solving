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

ll m, n, pig, a, k[1000], b, ans;
vector<Edge*> adj[111111];

int main()
{
    onlycc;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        cin >> pig;
        Edge *e1 = new Edge(i, pig), *e2 = new Edge(0, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[0].push_back(e1);
        adj[i].push_back(e2);
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int now = j+m*i, next = j+m*(i+1);
            Edge *e1 = new Edge(next, 1e9), *e2 = new Edge(now, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[now].push_back(e1);
            adj[next].push_back(e2);
        }
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        for(int j = 0; j < a; j++)
        {
            cin >> k[j];
            Edge *e1 = new Edge(m*n+i+1, 1e9), *e2 = new Edge(k[j]+m*i, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[k[j]+m*i].push_back(e1);
            adj[m*n+i+1].push_back(e2);
        }
        if(i < n-1)
        {
            for(int j = 0; j < a; j++)
            {
                for(int l = 0; l < a; l++)
                {
                    if(j == l) continue;
                    int now = k[j]+m*i, next = k[l]+m*(i+1);
                    Edge *e1 = new Edge(next, 1e9), *e2 = new Edge(now, 0);
                    e1->dual = e2;
                    e2->dual = e1;

                    adj[now].push_back(e1);
                    adj[next].push_back(e2);
                }
            }
        }

        cin >> b;
        Edge *e1 = new Edge(m*n+n+1, b), *e2 = new Edge(m*n+i+1, 0);
        e1->dual = e2;
        e2->dual = e1;

        adj[m*n+i+1].push_back(e1);
        adj[m*n+n+1].push_back(e2);
    }

    while(1)
    {
        int prev[111111];
        memset(prev, -1, sizeof(prev));
        Edge *path[111111];
        queue<int> q;

        q.push(0);
        while(!q.empty() && prev[m*n+n+1] == -1)
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
                    if(next == m*n+n+1) break;
                }
            }
        }
        if(prev[m*n+n+1] == -1) break;

        int flow = 1e9;
        for(int i = m*n+n+1; i != 0; i = prev[i]) flow = min(flow, path[i]->get_C());
        for(int i = m*n+n+1; i != 0; i = prev[i]) path[i]->update_F(flow);
        ans += flow;
    }
    cout << ans;

    return 0;
}
