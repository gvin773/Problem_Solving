#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, y, w, h, p[111111], area[111111], ans;
vector<pair<pii, pii>> v1, v2;

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
        p[py] = x;
    }
    else
    {
        p[py] += p[px];
        p[px] = y;
    }
}

bool cmp(const pair<pii, pii> &a, const pair<pii, pii> &b)
{
    if(a.first.second == b.first.second) return a.second.first < b.second.first;
    return a.first.second < b.first.second;
}

bool same(const pii &a, const pii &b)
{
    if(a.first < b.first) return a.second >= b.first;
    return b.second >= a.first;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> w >> h;
        v1.push_back({{i,x}, {y,y+h}});
        v1.push_back({{i,x+w}, {y,y+h}});
        v2.push_back({{i,y}, {x,x+w}});
        v2.push_back({{i,y+h}, {x,x+w}});
        p[i] = -w*h;
    }

    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    auto pre = v1[0];
    for(int i = 0; i < 2*n; i++)
    {
        auto now = v1[i];
        if(i == 0 || now.first.second != pre.first.second) pre = now;
        else
        {
            if(same(now.second, pre.second))
            {
                Merge(now.first.first, pre.first.first);
                pre = {{now.first.first, now.first.second}, {pre.second.first, max(pre.second.second, now.second.second)}};
            }
            else pre = now;
        }
    }
    pre = v2[0];
    for(int i = 0; i < 2*n; i++)
    {
        auto now = v2[i];
        if(i == 0 || now.first.second != pre.first.second) pre = now;
        else
        {
            if(same(now.second, pre.second))
            {
                Merge(now.first.first, pre.first.first);
                pre = {{now.first.first, now.first.second}, {pre.second.first, max(pre.second.second, now.second.second)}};
            }
            else pre = now;
        }
    }

    for(int i = 0; i < n; i++) if(p[i] < 0) ans = max(ans, -p[i]);
    cout << ans;

    return 0;
}
