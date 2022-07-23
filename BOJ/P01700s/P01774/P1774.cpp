#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, p[1001], a[1001], b[1001], c[1001], num, cnt, A, B;
ld ans;

int Find(int x)
{
    if(p[x] < 0) return x;
    p[x] = Find(p[x]);
    return p[x];
}

bool Merge(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px == py) return false;
    if(p[px] < p[py])
    {
        p[px] += p[py];
        p[py] = px;
    }
    else
    {
        p[py] += p[px];
        p[px] = py;
    }

    return true;
}

class Edge
{
public:
    int u, v;
    ld w;
    Edge(): Edge(-1, -1, 0){}
    Edge(int u1, int v1, ld w1): u(u1), v(v1), w(w1){}
    bool operator <(const Edge& O) const { return w < O.w; }
};

int main()
{
    onlycc;
    cin >> n >> m;

    Edge e[1000001];
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            e[num++] = Edge(i, j, sqrt((a[i]-a[j]) * (a[i]-a[j]) + (b[i]-b[j]) * (b[i]-b[j])));
        }
    }

    memset(p, -1, sizeof(p));
    for(int i = 0; i < m; i++)
    {
        cin >> A >> B;
        Merge(A, B);
    }

    sort(e, e+num);
    for(int i = 0; i < num; i++)
    {
        if(Merge(e[i].u, e[i].v))
        {
            ans += e[i].w;
            cnt = (p[e[i].u] < 0 ? p[e[i].u] : p[e[i].v]);
        }
        if(-cnt == n) break;
    }

    cout.precision(2);
    cout << fixed << ans;

    return 0;
}
