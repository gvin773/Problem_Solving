#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

ll n, x, y, ans;
vector<Point> p;

int main()
{
    onlycc;
    cin >> n >> x >> y;
    p.resize(n+1);
    p[n].x = x, p[n].y = y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }

    while(1)
    {
        sort(p.begin(), p.end()-1, cmp);
        for(int i = 1; i < p.size()-1; i++)
        {
            p[i].rx = p[i].x - p[0].x;
            p[i].ry = p[i].y - p[0].y;
        }
        sort(p.begin()+1, p.end()-1, cmp);

        stack<ll> s;
        s.push(0);
        s.push(1);
        int next = 2;
        while(next < p.size()-1)
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

        bool visited[1001] = {}, first = true;
        int dir = 0, T1 = s.top();
        while(s.size() >= 2)
        {
            int t1 = s.top(); s.pop();
            int t2 = s.top();
            visited[t1] = true;

            if(first) dir = ccw(p[t2], p[t1], p.back());
            else if(ccw(p[t2], p[t1], p.back()) != dir) goto fin;

            first = false;
        }
        if(ccw(p[T1], p[s.top()], p.back()) != dir) goto fin;
        visited[s.top()] = true;

        ans++;
        vector<Point> ret;
        for(int i = 0; i < p.size()-1; i++) if(!visited[i]) ret.push_back(Point(p[i].x, p[i].y));
        if(ret.size() <= 2) break;
        Point temp = p.back();
        p = ret;
        p.push_back(temp);
    }
    fin:;
    cout << ans;

    return 0;
}
