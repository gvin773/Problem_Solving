#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, a[11111], ans, sum, lo, hi;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    while(1)
    {
        if(sum >= m) sum -= a[lo++];
        else if(hi == n) break;
        else sum += a[hi++];
        if(sum == m) ans++;
    }
    cout << ans;

    return 0;
}
