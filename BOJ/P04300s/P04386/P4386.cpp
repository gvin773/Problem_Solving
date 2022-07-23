#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, p[1000], num, cnt;
ld a[1000], b[1000], ans;

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
    cin >> n;
    Edge e[10000];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            e[num++] = Edge(i, j, (a[i]-a[j])*(a[i]-a[j]) + (b[i]-b[j])*(b[i]-b[j]));
        }
    }

    memset(p, -1, sizeof(p));
    sort(e, e+num);

    for(int i = 0; ; i++)
    {
        if(Merge(e[i].u, e[i].v))
        {
            ans += sqrt(e[i].w);
            cnt++;
        }
        if(cnt == n-1) break;
    }
    cout << ans;

    return 0;
}
