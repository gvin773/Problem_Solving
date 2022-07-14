#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m;
ld sxs[2000], sys[2000], sxe[2000], sye[2000], axs[2000], ays[2000], axe[2000], aye[2000], ans = 1e12;

ld cross(ld x1, ld y1, ld x2, ld y2)
{
    return x1*y2 - x2*y1;
}

ld dist(ld x, ld y)
{
    return sqrt(x*x + y*y);
}

ld dot(ld x1, ld y1, ld x2, ld y2)
{
    return x1*x2 + y1*y2;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> sxs[i] >> sys[i] >> sxe[i] >> sye[i];
    for(int i = 0; i < m; i++) cin >> axs[i] >> ays[i] >> axe[i] >> aye[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ld ax = sxs[i], ay = sys[i], bx = sxe[i], by = sye[i], cx = axs[j], cy = ays[j], dx = axe[j], dy = aye[j];
            ans = min(ans, dist(ax-cx, ay-cy));
            ans = min(ans, dist(ax-dx, ay-dy));
            ans = min(ans, dist(bx-cx, by-cy));
            ans = min(ans, dist(bx-dx, by-dy));

            ld c1 = dot(bx-ax, by-ay, cx-ax, cy-ay);
            ld c2 = dot(-bx+ax, -by+ay, cx-bx, cy-by);
            if(c1*c2 >= 0)
            {
                ld height = abs(cross(bx-ax, by-ay, cx-ax, cy-ay)) / (dist(bx-ax, by-ay));
                ans = min(ans, height);
            }

            c1 = dot(bx-ax, by-ay, dx-ax, dy-ay);
            c2 = dot(-bx+ax, -by+ay, dx-bx, dy-by);
            if(c1*c2 >= 0)
            {
                ld height = abs(cross(bx-ax, by-ay, dx-ax, dy-ay)) / (dist(bx-ax, by-ay));
                ans = min(ans, height);
            }

            c1 = dot(dx-cx, dy-cy, ax-cx, ay-cy);
            c2 = dot(-dx+cx, -dy+cy, ax-dx, ay-dy);
            if(c1*c2 >= 0)
            {
                ld height = abs(cross(dx-cx, dy-cy, ax-cx, ay-cy)) / (dist(dx-cx, dy-cy));
                ans = min(ans, height);
            }

            c1 = dot(dx-cx, dy-cy, bx-cx, by-cy);
            c2 = dot(-dx+cx, -dy+cy, bx-dx, by-dy);
            if(c1*c2 >= 0)
            {
                ld height = abs(cross(dx-cx, dy-cy, bx-cx, by-cy)) / (dist(dx-cx, dy-cy));
                ans = min(ans, height);
            }
        }
    }
    cout.precision(10);
    cout << fixed << ans;

    return 0;
}
