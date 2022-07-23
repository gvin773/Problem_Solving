#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld a, b, c, d, e, f;

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

ld ans()
{
    ld len = dist(a, b, d, e);
    ld t1 = 2*acos((len*len + c*c - f*f) / (2*len*c));
    ld t2 = 2*acos((len*len + f*f - c*c) / (2*len*f));

    return c*c/2 * (t1 - sin(t1)) + f*f/2 * (t2 - sin(t2));
}

int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> e >> f;
    if(c > f)
    {
        swap(a, d);
        swap(b, e);
        swap(c, f);
    }

    cout.precision(3);
    cout << fixed;
    if(c + f < dist(a, b, d, e)) cout << 0.0;
    else if(f-c >= dist(a, b, d, e)) cout << c*c*M_PI;
    else cout << ans();

    return 0;
}
