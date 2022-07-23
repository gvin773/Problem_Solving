#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll p[4000];
vector<pair<pll, pll>> line;

ll Find(ll x)
{
    if(p[x] < 0) return x;
    p[x] = Find(p[x]);
    return p[x];
}

void Merge(ll x, ll y)
{
    ll px = Find(x);
    ll py = Find(y);
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

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    ll ret = x1*y2 - x2*y1;
    return (ret == 0 ? 0 : (ret > 0 ? 1 : -1));
}

int main()
{
    onlycc;
    memset(p, -1, sizeof(p));
    ll n = 2, X1, Y1, X2, Y2;

    for(int i = 0; i < n; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;
        if(X2 < X1 || (X1 == X2 && Y2 < Y1))
        {
            swap(X1, X2);
            swap(Y1, Y2);
        }
        line.push_back( make_pair( make_pair(X1, Y1), make_pair(X2, Y2) ) );
    }

    for(int i = 0; i < n; i++)
    {
        for(int idx = 0; idx < n; idx++)
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
            	if(y2 >= b) Merge(i, idx);
            	else continue;
            }
            else if(y1 == y2 && y2 == b && b == d)
            {
            	if(x2 >= a) Merge(i, idx);
            	else continue;
            }
            else if((y2-y1)*(a-x2) == (b-y2)*(x2-x1) && (b-y2)*(c-a) == (d-b)*(a-x2))
            {
            	if(x2 >= a) Merge(i, idx);
            	else continue;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, d-b, x1-c, y1-d) * cross(c-a, d-b, x2-c, y2-d) <= 0) Merge(i, idx);
        }
    }

    sort(p, p+n);
    cout << (-p[0] == 2 ? 1 : 0);

    return 0;
}
