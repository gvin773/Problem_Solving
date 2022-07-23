#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, p[200000], a, b, c;

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
    int u, v, w;
    Edge(): Edge(-1, -1, 0){}
    Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
    bool operator <(const Edge& O) const { return w < O.w; }
};

int main()
{
    onlycc;
    while(1)
    {
        cin >> m >> n;
        if(m == 0 && n == 0) break;

        ll ans = 0, cnt = 0;
        Edge e[200000];
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            e[i] = Edge(a, b, c);
            ans += c;
        }

        memset(p, -1, sizeof(p));
        sort(e, e+n);

        for(int i = 0; ; i++)
        {
            if(Merge(e[i].u, e[i].v))
            {
                ans -= e[i].w;
                cnt++;
            }
            if(cnt == m-1) break;
        }
        cout << ans << '\n';
    }

    return 0;
}
