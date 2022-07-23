#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[100000], x, ans;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    sort(a, a+n);

    ll lo = 0, hi = n-1;
    while(lo < hi)
    {
        ll sum = a[lo] + a[hi];
        if(sum == x) ans++;
        if(sum < x) lo++;
        else hi--;
    }
    cout << ans;

    return 0;
}
