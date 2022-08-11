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

ll k, n;
vector<Edge*> adj[11111];
string str;

int main()
{
    onlycc;
    for(int tc = 1; ; tc++)
    {
        cin >> k >> n;
        if(k == 0 && n == 0) break;
        cin.ignore();
        for(int i = 0; i < 11111; i++) adj[i].clear();
        for(int i = 1; i <= n; i++)
        {
            getline(cin, str);
            stringstream ss(str);
            ss.str(str);

            string x;
            while(ss >> x)
            {
                int xx = stoi(x);
                xx = xx*2-2;

                Edge *e1 = new Edge(xx, 1), *e2 = new Edge(i*2-1, 0);
                e1->dual = e2;
                e2->dual = e1;

                adj[i*2-1].push_back(e1);
                adj[xx].push_back(e2);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            int x = i*2-2, o = i*2-1;
            Edge *e1 = new Edge(o, 1), *e2 = new Edge(x, 0);
            e1->dual = e2;
            e2->dual = e1;

            adj[x].push_back(e1);
            adj[o].push_back(e2);
        }

        cout << "Case " << tc << ":\n";
        for(int z = 0; z < k; z++)
        {
            int prev[11111];
            memset(prev, -1, sizeof(prev));
            Edge *path[11111];
            queue<int> q;

            q.push(1*2-1);
            while(!q.empty() && prev[2*2-2] == -1)
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
                        if(next == 2*2-2) break;
                    }
                }
            }
            if(prev[2*2-2] == -1)
            {
                cout << "Impossible\n";
                goto xy;
            }
            for(int i = 2*2-2; i != 1*2-1; i = prev[i]) path[i]->update_F(1);
        }

        for(int z = 0; z < k; z++)
        {
            int prev = -46, now = 1*2-1;
            while(now != 2*2-2)
            {
                if(prev/2 != now/2) cout << now/2+1 << ' ';
                prev = now;

                for(auto e : adj[now])
                {
                    int next = e->E;
                    if(e->F > 0)
                    {
                        e->F--;
                        now = next;
                        break;
                    }
                }
            }
            cout << 2 << '\n';
        }

        xy:;
        cout << '\n';
    }

    return 0;
}
