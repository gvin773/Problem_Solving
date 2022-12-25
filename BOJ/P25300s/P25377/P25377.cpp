#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a, b, ans = 987654321;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        if(a <= b) ans = min(ans, b);
    }
    if(ans == 987654321) cout << -1;
    else cout << ans;

    return 0;
}
