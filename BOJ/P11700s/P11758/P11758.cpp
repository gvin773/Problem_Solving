#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll a, b, c, d, e, f, x;

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2 - x2*y1;
}

int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> e >> f;
    if((x = cross(c-a, d-b, e-c, f-d)) > 0) cout << 1;
    else if(x < 0) cout << -1;
    else cout << 0;

    return 0;
}
