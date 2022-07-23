#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, p[100000], a[100000], b[100000], c[100000], num, cnt, ans;
vector<pll> A, B, C;

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
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        A.push_back({a[i], i});
        B.push_back({b[i], i});
        C.push_back({c[i], i});
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    Edge e[400000];
    for(int i = 0; i < A.size()-1; i++) e[num++] = Edge(A[i].second, A[i+1].second, min(min(abs(a[A[i].second] - a[A[i+1].second]), abs(b[A[i].second] - b[A[i+1].second])), abs(c[A[i].second] - c[A[i+1].second])));
    for(int i = 0; i < B.size()-1; i++) e[num++] = Edge(B[i].second, B[i+1].second, min(min(abs(a[B[i].second] - a[B[i+1].second]), abs(b[B[i].second] - b[B[i+1].second])), abs(c[B[i].second] - c[B[i+1].second])));
    for(int i = 0; i < C.size()-1; i++) e[num++] = Edge(C[i].second, C[i+1].second, min(min(abs(a[C[i].second] - a[C[i+1].second]), abs(b[C[i].second] - b[C[i+1].second])), abs(c[C[i].second] - c[C[i+1].second])));

    memset(p, -1, sizeof(p));
    sort(e, e+num);

    for(int i = 0; ; i++)
    {
        if(Merge(e[i].u, e[i].v))
        {
            ans += e[i].w;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    cout << ans;

    return 0;
}
