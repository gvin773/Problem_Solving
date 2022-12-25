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
    ll x, y, rx, ry;
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

ll n, x, y, cnt;
vector<Point> p;
char z;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        if(z == 'N') continue;
        p.push_back(Point(x, y));
    }
    sort(p.begin(), p.end(), cmp);
    for(int i = 1; i < p.size(); i++)
    {
        p[i].rx = p[i].x - p[0].x;
        p[i].ry = p[i].y - p[0].y;
    }
    sort(p.begin()+1, p.end(), cmp);

    cnt = p.size()-1;
    for(int i = p.size()-1; i > 0; i--)
    {
        if(ccw(p[0], p[cnt], p[cnt-1]) == 0) cnt--;
        else break;
    }
    reverse(p.begin()+cnt, p.end());

    ll mx = LLONG_MAX, my = LLONG_MAX, idx;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].x < mx)
        {
            idx = i;
            mx = p[i].x, my = p[i].y;
        }
        if(p[i].x == mx && p[i].y < my)
        {
            idx = i;
            my = p[i].y;
        }
    }

    cout << p.size() << '\n';
    for(int i = idx; i < p.size(); i++) cout << p[i].x << ' ' << p[i].y << '\n';
    for(int i = 0; i < idx; i++) cout << p[i].x << ' ' << p[i].y << '\n';

    return 0;
}
