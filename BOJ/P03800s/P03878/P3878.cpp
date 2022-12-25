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

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    ll ret = x1*y2 - x2*y1;
    return (ret == 0 ? 0 : (ret > 0 ? 1 : -1));
}

bool intersection(vector<pair<pll, pll>> &line)
{
    for(auto x : line) if(x.second.first < x.first.first || (x.first.first == x.second.first && x.second.second < x.first.second)) swap(x.first, x.second);

    for(int i = 0; i < 2; i++)
    {
        for(int idx = 0; idx < 2; idx++)
        {
            if(i == idx) continue;
            auto before = line[i];
            auto now = line[idx];

            ll x1 = before.first.first, y1 = before.first.second, x2 = before.second.first, y2 = before.second.second;
            ll a = now.first.first, b = now.first.second, c = now.second.first, d = now.second.second;

            if(a < x1 || (a == x1 && b < y1))
            {
                swap(x1, a);
                swap(y1, b);
                swap(x2, c);
                swap(y2, d);
            }

            if(x1 == x2 && x2 == a && a == c)
            {
            	if(y2 >= b) return true;
            	else continue;
            }
            else if(y1 == y2 && y2 == b && b == d)
            {
            	if(x2 >= a) return true;
            	else continue;
            }
            else if((y2-y1)*(a-x2) == (b-y2)*(x2-x1) && (b-y2)*(c-a) == (d-b)*(a-x2))
            {
            	if(x2 >= a) return true;
            	else continue;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, d-b, x1-c, y1-d) * cross(c-a, d-b, x2-c, y2-d) <= 0) return true;
        }
    }

    return false;
}

ll tc, n, m, x, y;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        Point p1[1000], p2[1000];
        stack<ll> s1, s2;

        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            p1[i].x = x;
            p1[i].y = y;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            p2[i].x = x;
            p2[i].y = y;
        }

        sort(p1, p1+n, cmp), sort(p2, p2+m, cmp);
        for(int i = 1; i < n; i++)
        {
            p1[i].rx = p1[i].x - p1[0].x;
            p1[i].ry = p1[i].y - p1[0].y;
        }
        for(int i = 1; i < m; i++)
        {
            p2[i].rx = p2[i].x - p2[0].x;
            p2[i].ry = p2[i].y - p2[0].y;
        }
        sort(p1+1, p1+n, cmp), sort(p2+1, p2+m, cmp);

        s1.push(0), s2.push(0);
        s1.push(1), s2.push(1);
        int next1 = 2, next2 = 2;
        while(next1 < n)
        {
            while(s1.size() >= 2)
            {
                int t1 = s1.top(); s1.pop();
                int t2 = s1.top();

                if(ccw(p1[t2], p1[t1], p1[next1]) > 0)
                {
                    s1.push(t1);
                    break;
                }
            }

            s1.push(next1++);
        }
        while(next2 < m)
        {
            while(s2.size() >= 2)
            {
                int t1 = s2.top(); s2.pop();
                int t2 = s2.top();

                if(ccw(p2[t2], p2[t1], p2[next2]) > 0)
                {
                    s2.push(t1);
                    break;
                }
            }

            s2.push(next2++);
        }
        if(n < 3)
        {
            while(!s1.empty()) s1.pop();
            for(int i = 0; i < n; i++) s1.push(i);
        }
        if(m < 3)
        {
            while(!s2.empty()) s2.pop();
            for(int i = 0; i < m; i++) s2.push(i);
        }

        vector<ll> v1, v2;
        stack<ll> st1 = s1, st2 = s2;
        while(!s1.empty())
        {
            v1.push_back(s1.top());
            s1.pop();
        }
        while(!s2.empty())
        {
            v2.push_back(s2.top());
            s2.pop();
        }
        s1 = st1, s2 = st2;

        if(s1.size() < 3) goto next_step;
        for(auto next : v2)
        {
            stack<ll> temp = s1;
            bool first = true, checked = true;
            int dir = 0, T1 = s1.top();
            while(s1.size() >= 2)
            {
                int t1 = s1.top(); s1.pop();
                int t2 = s1.top();

                if(first) dir = ccw(p1[t2], p1[t1], p2[next]);
                else if(ccw(p1[t2], p1[t1], p2[next]) != dir) checked = false;
                first = false;
            }
            if(ccw(p1[T1], p1[s1.top()], p2[next]) != dir) checked = false;

            s1 = temp;
            if(checked && v1.size() > 1) goto fin;
        }

        next_step:;
        if(s2.size() < 3) goto nnext_step;
        for(auto next : v1)
        {
            stack<ll> temp = s2;
            bool first = true, checked = true;
            int dir = 0, T1 = s2.top();
            while(s2.size() >= 2)
            {
                int t1 = s2.top(); s2.pop();
                int t2 = s2.top();

                if(first) dir = ccw(p2[t2], p2[t1], p1[next]);
                else if(ccw(p2[t2], p2[t1], p1[next]) != dir) checked = false;
                first = false;
            }
            if(ccw(p2[T1], p2[s2.top()], p1[next]) != dir) checked = false;

            s2 = temp;
            if(checked && v2.size() > 1) goto fin;
        }

        nnext_step:;
        for(int i = 0; i < (int)v1.size(); i++)
        {
            vector<pair<pll, pll>> line;
            line.resize(2);
            line[0] = {{p1[v1[i]].x, p1[v1[i]].y}, {p1[v1[(i+1)%v1.size()]].x, p1[v1[(i+1)%v1.size()]].y}};
            for(int j = 0; j < (int)v2.size(); j++)
            {
                line[1] = {{p2[v2[j]].x, p2[v2[j]].y}, {p2[v2[(j+1)%v2.size()]].x, p2[v2[(j+1)%v2.size()]].y}};
                if(intersection(line)) goto fin;
            }
        }

        cout << "YES\n";
        continue;
        fin: cout << "NO\n";
    }

    return 0;
}
