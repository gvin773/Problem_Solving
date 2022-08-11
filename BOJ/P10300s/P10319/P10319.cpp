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

ll tc, n, i, g, s, m, r, a, b, p, t, ans;
vector<Edge*> adj[111111];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ans = 0;
        for(int z = 0; z < 111111; z++) adj[z].clear();
        cin >> n >> i >> g >> s >> m;
        {
            Edge *e1 = new Edge(i, g), *e2 = new Edge(0, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[0].push_back(e1);
            adj[i].push_back(e2);
        }
        for(int z = 0; z < m; z++)
        {
            cin >> a;
            for(int zz = 0; zz <= s; zz++)
            {
                Edge *e1 = new Edge(s*n+n+1, 1e9), *e2 = new Edge(zz*n+a, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[zz*n+a].push_back(e1);
                adj[s*n+n+1].push_back(e2);
            }
        }
        cin >> r;
        for(int z = 0; z < r; z++)
        {
            cin >> a >> b >> p >> t;
            for(int Time = 0; Time+t <= s; Time++)
            {
                Edge *e1 = new Edge((Time+t)*n+b, p), *e2 = new Edge(Time*n+a, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[Time*n+a].push_back(e1);
                adj[(Time+t)*n+b].push_back(e2);
            }
        }
        for(int now = 1; now <= n; now++)
        {
            for(int z = 0; z < s; z++)
            {
                Edge *e1 = new Edge((z+1)*n+now, 1e9), *e2 = new Edge(z*n+now, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[z*n+now].push_back(e1);
                adj[(z+1)*n+now].push_back(e2);
            }
        }

        while(1)
        {
            int prev[111111];
            memset(prev, -1, sizeof(prev));
            Edge *path[111111];
            queue<int> q;

            q.push(0);
            while(!q.empty() && prev[s*n+n+1] == -1)
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
                        if(next == s*n+n+1) break;
                    }
                }
            }
            if(prev[s*n+n+1] == -1) break;

            int flow = 1e9;
            for(int z = s*n+n+1; z != 0; z = prev[z]) flow = min(flow, path[z]->get_C());
            for(int z = s*n+n+1; z != 0; z = prev[z]) path[z]->update_F(flow);
            ans += flow;
        }

        cout << ans << '\n';
    }

    return 0;
}
