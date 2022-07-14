#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, x[10000], y[10000];
long double ans;

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2 - x2*y1;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 1; i < n-1; i++) ans += (cross(x[i]-x[0], y[i]-y[0], x[i+1]-x[0], y[i+1]-y[0]) / (double)2);
    cout.precision(1);
    cout << fixed << abs(ans);

    return 0;
}
