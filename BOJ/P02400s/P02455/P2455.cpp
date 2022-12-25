#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, now, ans;

int main()
{
    onlycc;
    for(int i = 0; i < 4; i++)
    {
        cin >> a >> b;
        now -= a;
        now += b;
        ans = max(ans, now);
    }
    cout << ans;

    return 0;
}
