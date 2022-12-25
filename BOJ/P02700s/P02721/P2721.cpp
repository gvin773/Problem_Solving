#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, ans;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        ans = 0;
        cin >> n;
        for(ll k = 1; k <= n; k++) ans += k*(k+1)*(k+2)/2;
        cout << ans << '\n';
    }

    return 0;
}
