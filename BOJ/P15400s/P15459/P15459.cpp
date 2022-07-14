#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, f[100010], s[100010], p[100010];
pll sidx[100010];

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
    if(f[px] < f[py])
    {
        f[px] += f[py];
        p[py] = px;
    }
    else
    {
        f[py] += f[px];
        p[px] = py;
    }
}

int main()
{
    onlycc;
    memset(p, -1, sizeof(p));
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> f[i] >> s[i];
        sidx[i] = {s[i], i};
    }
    sort(sidx, sidx+n);

    for(int i = 0; i < n; i++)
    {
        int now = sidx[i].second;
        if(f[Find(now)] >= m)
        {
            cout << s[now];
            break;
        }
        if(0 < now && s[now-1] <= s[now])
        {
            Merge(now, now-1);
            if(f[Find(now)] >= m)
            {
                cout << s[now];
                break;
            }
        }
        if(now < n-1 && s[now+1] <= s[now])
        {
            Merge(now, now+1);
            if(f[Find(now)] >= m)
            {
                cout << s[now];
                break;
            }
        }
    }

    return 0;
}
