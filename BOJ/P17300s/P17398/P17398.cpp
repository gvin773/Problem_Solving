#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, q, X, Y, p[100010], ans;
unordered_map<ll, pll> s;
vector<pll> v;

int Find(int x)
{
    if(p[x] < 0) return x;
    p[x] = Find(p[x]);
    return p[x];
}

void Merge(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px == py) return;
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
}

int main()
{
    onlycc;
    memset(p, -1, sizeof(p));
    cin >> n >> m >> q;
    for(int i = 1 ; i <= m; i++)
    {
        cin >> X >> Y;
        s[i] = {X, Y};
    }
    for(int i = 0; i < q; i++)
    {
        cin >> X;
        v.push_back(s[X]);
        s.erase(X);
    }

    for(auto x : s)
    {
        int va = x.second.first, vb = x.second.second;
        Merge(va, vb);
    }
    for(auto x : v)
    {
        int va = x.first, vb = x.second;
        if(Find(va) != Find(vb)) ans += p[Find(va)]*p[Find(vb)];
        Merge(va, vb);
    }
    cout << ans;

    return 0;
}

