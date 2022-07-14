#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, k, dp[20][250][250];

ll f(int x, int y, int an)
{
    if(x == 0) return 1;
    ll &ret = dp[x][y][an];
    if(ret != -1) return ret;
    if(x == 1) return ret = (y >= an);

    ret = 0;
    for(int now = an; now <= m; now++)
    {
        if(y-now < 0) break;
        ret += f(x-1, y-now, now);
    }

    return ret;
}

void track(ll x, ll y, ll an, ll kth)
{
    if(x == 0) return;
    if(x == 1)
    {
        cout << y << ' ';
        return;
    }

    for(int now = an; now <= m; now++)
    {
        ll pivot = f(x-1, y-now, now);
        if(pivot >= kth)
        {
            cout << now << ' ';
            track(x-1, y-now, now, kth);
            break;
        }
        else kth -= pivot;
    }
}

int main()
{
    onlycc;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    track(n, m, 1, k);

    return 0;
}
