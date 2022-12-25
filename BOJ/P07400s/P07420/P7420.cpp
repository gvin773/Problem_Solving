#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

class Point
{
public:
    ll x, y, rx, ry;
    Point() : Point(0, 0, 1, 0){}
    Point(ll x1, ll y1) : Point(x1, y1, 1, 0){}
    Point(ll x1, ll y1, ll rx1, ll ry1) : x(x1), y(y1), rx(rx1), ry(ry1){}
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

ld dist(const Point &a, const Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

ll n, l, x, y;
Point p[10000];
stack<ll> s;
ld len;

int main()
{
    onlycc;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }
    sort(p, p+n, cmp);
    for(int i = 1; i < n; i++)
    {
        p[i].rx = p[i].x - p[0].x;
        p[i].ry = p[i].y - p[0].y;
    }
    sort(p+1, p+n, cmp);

    s.push(0);
    s.push(1);
    int next = 2;
    while(next < n)
    {
        while(s.size() >= 2)
        {
            int t1 = s.top(); s.pop();
            int t2 = s.top();

            if(ccw(p[t2], p[t1], p[next]) > 0)
            {
                s.push(t1);
                break;
            }
        }

        s.push(next++);
    }
    len = 2*M_PI*l;

    int T1 = s.top();
    while(s.size() >= 2)
    {
        int t1 = s.top(); s.pop();
        int t2 = s.top();

        len += dist(p[t1], p[t2]);
    }
    len += dist(p[T1], p[s.top()]);
    cout << round(len);

    return 0;
}
