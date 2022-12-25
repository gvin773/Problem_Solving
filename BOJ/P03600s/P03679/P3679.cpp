#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

class Point
{
public:
    ll x, y, rx, ry, idx;
    Point() : Point(0, 0, 1, 0){}
    Point(ll x1, ll y1) : Point(x1, y1, 1, 0){}
    Point(ll x1, ll y1, ll rx1, ll ry1) : x(x1), y(y1), rx(rx1), ry(ry1){}

    Point operator -(const Point &b)
    {
        Point ret;
        ret.x = x-b.x;
        ret.y = y-b.y;
        ret.rx = rx-b.rx;
        ret.ry = ry-b.ry;

        return ret;
    }
};

bool cmp(const Point &a, const Point &b)
{
    if(a.ry*b.rx != a.rx*b.ry) return a.ry*b.rx < a.rx*b.ry;
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

ll ccw(const Point &a, const Point &b, const Point &c)
{
    ll ret = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    if(ret < 0) return -1;
    if(ret > 0) return 1;
    return 0;
}

ll tc, n, x, y, cnt;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        Point p[200000] = {};
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            p[i].x = x;
            p[i].y = y;
            p[i].idx = i;
        }
        sort(p, p+n, cmp);
        for(int i = 1; i < n; i++)
        {
            p[i].rx = p[i].x - p[0].x;
            p[i].ry = p[i].y - p[0].y;
        }
        sort(p+1, p+n, cmp);

        cnt = n-1;
        for(int i = n-1; i > 0; i--)
        {
            if(ccw(p[0], p[cnt], p[cnt-1]) == 0) cnt--;
            else break;
        }
        reverse(p+cnt, p+n);
        for(int i = 0; i < n; i++) cout << p[i].idx << ' ';
        cout << '\n';
    }

    return 0;
}
