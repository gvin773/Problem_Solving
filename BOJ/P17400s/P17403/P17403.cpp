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
    Point() : Point(0, 0, 1, 0, 0){}
    Point(ll x1, ll y1, ll idx1) : Point(x1, y1, 1, 0, idx1){}
    Point(ll x1, ll y1, ll rx1, ll ry1, ll idx1) : x(x1), y(y1), rx(rx1), ry(ry1), idx(idx1){}

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

ll n, x, y, F[1000];
vector<Point> p;

int main()
{
    onlycc;
    cin >> n;
    p.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
        p[i].idx = i;
    }

    for(int cnt = 1; ; cnt++)
    {
        if(p.size() < 3) break;
        sort(p.begin(), p.end(), cmp);
        for(int i = 1; i < p.size(); i++)
        {
            p[i].rx = p[i].x - p[0].x;
            p[i].ry = p[i].y - p[0].y;
        }
        sort(p.begin()+1, p.end(), cmp);

        stack<ll> s;
        s.push(0);
        s.push(1);
        int next = 2;
        while(next < p.size())
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
        if(s.size() < 3) break;

        bool visited[1000] = {};
        while(!s.empty())
        {
            visited[s.top()] = true;
            s.pop();
        }

        vector<Point> ret;
        for(int i = 0; i < p.size(); i++)
        {
            if(!visited[i]) ret.push_back(Point(p[i].x, p[i].y, p[i].idx));
            else F[p[i].idx] = cnt;
        }
        p = ret;
    }
    for(int i = 0; i < n; i++) cout << F[i] << ' ';

    return 0;
}
