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
    int u, v, w;
    Edge(): Edge(-1, -1, 0){}
    Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
    bool operator <(const Edge& O) const { return w < O.w; }
};

const int SIZE = 300000;
ll n, m, a, b, c, q, Parent[SIZE], num_children[SIZE], T[SIZE], p[SIZE][20], depth[SIZE];
vector<int> adj[SIZE];
Edge e[SIZE];

void init(int now)
{
    for(auto next : adj[now])
    {
        if(depth[next] == -1)
        {
            depth[next] = depth[now] + 1;
            p[next][0] = now;
            init(next);
        }
    }
}

int LCA(int u, int v)
{
    int diff = depth[u] - depth[v];
    if(diff < 0) swap(u, v), diff *= (-1);

    for(int j = 0; diff; j++)
    {
        if(diff&1) u = p[u][j];
        diff >>= 1;
    }

    if(u != v)
    {
        for(int j = 19; j >= 0; j--)
        {
            if(p[u][j] != -1 && p[v][j] != -1 && p[u][j] != p[v][j])
            {
                u = p[u][j];
                v = p[v][j];
            }
        }

        u = p[u][0];
    }

    return u;
}

int Find(int x)
{
    if(Parent[x] < 0) return x;
    Parent[x] = Find(Parent[x]);
    return Parent[x];
}

bool Merge(int x, int y, int Time, int idx)
{
    int px = Find(x);
    int py = Find(y);
    if(px == py) return false;

    adj[idx].push_back(px);
    adj[idx].push_back(py);
    adj[px].push_back(idx);
    adj[py].push_back(idx);

    Parent[idx] = Parent[py];
    Parent[py] = idx;
    Parent[idx] += Parent[px];
    Parent[px] = idx;

    T[idx] = Time;
    return true;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        e[i] = Edge(a, b, c);
    }

    memset(Parent, -1, sizeof(Parent));
    sort(e, e+m);
    int cnt = 1;
    for(int i = 0; i < m; i++)
    {
        if(Merge(e[i].u, e[i].v, e[i].w, n+cnt))
        {
            num_children[n+cnt] = Parent[n+cnt];
            cnt++;
        }
    }

    memset(p, -1, sizeof(p));
    memset(depth, -1, sizeof(depth));
    unordered_set<int> roots;
    for(int i = 1; i <= n; i++) roots.insert(Find(i));
    for(auto i : roots) depth[i] = 0;
    for(auto i : roots) init(i);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 1; j < 2*n; j++)
        {
            if(p[j][i] == -1) continue;
            p[j][i+1] = p[p[j][i]][i];
        }
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if(Find(a) != Find(b))
        {
            cout << -1 << '\n';
            continue;
        }

        int ret = LCA(a, b);
        cout << T[ret] << ' ' << -num_children[ret] << '\n';
    }

    return 0;
}
