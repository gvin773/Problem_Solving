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

ll tc, n, m, a[100][100], sum, ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<Edge*> adj[6666];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        sum = 0;
        ans = 0;
        for(int i = 0; i < 6666; i++) adj[i].clear();
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                sum += a[i][j];
            }
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i%2 == j%2)
                {
                    Edge *e1 = new Edge((i-1)*m+j, a[i][j]), *e2 = new Edge(0, 0);
                    e1->dual = e2;
                    e2->dual = e1;

                    adj[0].push_back(e1);
                    adj[(i-1)*m+j].push_back(e2);
                }
                else
                {
                    Edge *e1 = new Edge(6161, a[i][j]), *e2 = new Edge((i-1)*m+j, 0);
                    e1->dual = e2;
                    e2->dual = e1;

                    adj[(i-1)*m+j].push_back(e1);
                    adj[6161].push_back(e2);
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i%2 != j%2) continue;
                for(int z = 0; z < 4; z++)
                {
                    int nx = i+dx[z], ny = j+dy[z];
                    if(0 < nx && nx <= n && 0 < ny && ny <= m)
                    {
                        Edge *e1 = new Edge((nx-1)*m+ny, 1e9), *e2 = new Edge((i-1)*m+j, 0);
                        e1->dual = e2;
                        e2->dual = e1;

                        adj[(i-1)*m+j].push_back(e1);
                        adj[(nx-1)*m+ny].push_back(e2);
                    }
                }
            }
        }

        while(1)
        {
            int prev[6666];
            memset(prev, -1, sizeof(prev));
            Edge *path[6666];
            queue<int> q;

            q.push(0);
            while(!q.empty() && prev[6161] == -1)
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
                        if(next == 6161) break;
                    }
                }
            }
            if(prev[6161] == -1) break;

            int flow = 1e9;
            for(int i = 6161; i != 0; i = prev[i]) flow = min(flow, path[i]->get_C());
            for(int i = 6161; i != 0; i = prev[i]) path[i]->update_F(flow);
            ans += flow;
        }

        cout << sum - ans << '\n';
    }

    return 0;
}
