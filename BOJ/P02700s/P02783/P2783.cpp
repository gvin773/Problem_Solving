#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld x, y, n, ans;

int main()
{
    onlycc;
    cin >> x >> y >> n;
    ans = x/y;
    while(n--)
    {
        cin >> x >> y;
        ans = min(ans, x/y);
    }
    cout << ans*1000;

    return 0;
}
