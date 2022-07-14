#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, a, b, p[500000], ans;
bool flag;

int Find(int x)
{
    if(p[x] < 0) return x;
    int newp = Find(p[x]);
    p[x] = newp;
    return p[x];
}

void Merge(int x, int y)
{
    int px = Find(x), py = Find(y);

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
    cin >> n >> m;
    memset(p, -1, sizeof(p));
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if(!flag && Find(a) == Find(b))
        {
            ans = i;
            flag = true;
        }
        Merge(a, b);
    }
    cout << ans;

    return 0;
}
