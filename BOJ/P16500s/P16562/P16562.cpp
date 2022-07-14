#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, k, p[10001], a[10001], v, w, ret;
unordered_set<ll> s;

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
    if(a[px] < a[py])
    {
        p[px] += p[py];
        p[py] = x;
    }
    else
    {
        p[py] += p[px];
        p[px] = y;
    }
}

int main()
{
    onlycc;
    cin >> n >> m >> k;
    memset(p, -1, sizeof(p));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        cin >> v >> w;
        Merge(v, w);
    }
    for(int i = 1; i <= n; i++)
    {
        int root = Find(i);
        if(s.find(root) == s.end())
        {
            s.insert(root);
        }
    }
    for(auto x : s) ret += a[x];
    if(ret <= k) cout << ret;
    else cout << "Oh no";

    return 0;
}
