#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a, d, g, ans;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> a >> d >> g;
        a = a*(d+g)*(a == d+g ? 2 : 1);
        ans = max(ans, a);
    }
    cout << ans;

    return 0;
}
