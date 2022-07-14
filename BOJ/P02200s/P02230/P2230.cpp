#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, a[100000], lo, hi, ans = LLONG_MAX;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    while(1)
    {
        if(abs(a[lo]-a[hi]) >= m) ans = min(ans, abs(a[lo]-a[hi]));
        if(abs(a[lo]-a[hi]) >= m) lo++;
        else if(hi == n-1) lo++;
        else hi++;
        if(lo == n) break;

    }
    cout << ans;

    return 0;
}
