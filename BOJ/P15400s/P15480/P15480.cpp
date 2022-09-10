#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 101010;
ll n, m, a, b, c, p[SIZE][20], depth[SIZE], ab, bc, ca;
vector<int> Edge[SIZE];

void init(int now)
{
    for(auto next : Edge[now])
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

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }

    memset(p, -1, sizeof(p));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    init(1);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(p[j][i] == -1) continue;
            p[j][i+1] = p[p[j][i]][i];
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        ab = LCA(a, b);
        bc = LCA(b, c);
        ca = LCA(c, a);

        if(depth[ab] < depth[bc]) swap(ab, bc);
        if(depth[ab] < depth[ca]) swap(ab, ca);
        cout << ab << '\n';
    }

    return 0;
}
