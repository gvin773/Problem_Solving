#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, y, d, t, j;
ld len, ans;

int main()
{
    onlycc;
    cin >> x >> y >> d >> t;

    ans = len = sqrt(x*x + y*y);
    j = len / d;

    ll temp = j * t;
    len = len - (j * d);
    ans = min(ans, temp+len);

    len = sqrt(x*x + y*y);
    temp = (j + 1) * t;
    len = (j + 1) * d - len;
    ans = min(ans, temp+len);

    if(j) ans = min(ans, ld(j+1)*t);
    else if(len < d) ans = min(ans, (ld)2*t);

    cout.precision(10);
    cout << fixed << ans;

    return 0;
}
