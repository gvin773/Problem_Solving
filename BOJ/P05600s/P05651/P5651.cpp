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

ll tc, n, m, a, b, c, ans;
vector<Edge*> adj[555];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ans = 0;
        for(int i = 0; i < 555; i++) adj[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            Edge *e1 = new Edge(b, c), *e2 = new Edge(a, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[a].push_back(e1);
            adj[b].push_back(e2);
        }

        while(1)
        {
            int prev[555];
            memset(prev, -1, sizeof(prev));
            Edge *path[555];
            queue<int> q;

            q.push(1);
            while(!q.empty() && prev[n] == -1)
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
                        if(next == n) break;
                    }
                }
            }
            if(prev[n] == -1) break;

            int flow = 1e9;
            for(int i = n; i != 1; i = prev[i]) flow = min(flow, path[i]->get_C());
            for(int i = n; i != 1; i = prev[i]) path[i]->update_F(flow);
        }

        for(int i = 1; i <= n; i++)
        {
            for(auto &e : adj[i])
            {
                if(e->get_C() == 0 && e->C > 0)
                {
                    e->C--;
                    e->F--;
                    bool visited[555] = {};
                    queue<int> q;

                    q.push(i);
                    while(!q.empty())
                    {
                        int now = q.front();
                        q.pop();

                        for(auto ee : adj[now])
                        {
                            int next = ee->E;
                            if(ee->get_C() > 0 && !visited[next])
                            {
                                q.push(next);
                                visited[next] = true;
                                if(next == e->E) break;
                            }
                        }
                    }
                    if(!visited[e->E]) ans++;
                    e->C++;
                    e->F++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
