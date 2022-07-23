#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, w, n, X[1010], Y[1010], r[1010], p[1010], num, cnt;
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

ld get_dist(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        Edge e[1000100];
        memset(p, -1, sizeof(p));
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(r, 0, sizeof(r));
        cin >> w >> n;
        for(int i = 0; i < n; i++) cin >> X[i] >> Y[i] >> r[i];
        X[n+1] = w;
        if(n == 0)
        {
            cout << w/(double)2 << '\n';
            continue;
        }

        num = 0;
        for(int i = 0; i < n+2; i++)
        {
            for(int j = i+1; j < n+2; j++)
            {
                if(j == n || j == n+1) e[num++] = Edge(i, j, abs(X[i]-X[j]) > r[i] ? abs(X[i]-X[j])-r[i] : 0);
                else
                {
                    ld temp = get_dist(X[i], Y[i], X[j], Y[j]);
                    e[num++] = Edge(i, j, temp > r[i]+r[j] ? temp-r[i]-r[j] : 0);
                }
            }
        }

        sort(e, e+num);
        cnt = 0, ans = w;
        for(int i = 0; ; i++)
        {
            if(Find(n) == Find(n+1)) break;
            if(Merge(e[i].u, e[i].v))
            {
                ans = e[i].w;
                cnt++;
            }
        }
        cout.precision(6);
        cout << fixed << (Find(n) == Find(n+1) ? ans/2 : 0) << '\n';
    }

    return 0;
}
