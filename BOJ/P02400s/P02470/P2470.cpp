#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a[100000], m = LLONG_MAX, L, R;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    ll lo = 0, hi = n-1;
    while(lo < hi)
    {
        ll sum = a[lo] + a[hi];
        if(abs(m) > abs(sum))
        {
            m = sum;
            L = a[lo];
            R = a[hi];
        }
        if(sum < 0) lo++;
        else hi--;
    }
    cout << L << ' ' << R;

    return 0;
}
