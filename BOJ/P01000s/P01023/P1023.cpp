#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k, dp[70][70];

ll f(int x, int y)
{
    if(x == 0) return 1;
    ll &ret = dp[x][y];
    if(ret != -1) return ret;
    if(x == y) return ret = (1LL<<x)-1;
    return ret = f(x-1, y+1) + (y > 0 ? f(x-1, y-1) : 1LL<<(x-1));
}

void track(ll x, ll y, ll kth)
{
    if(x == 0) return;
    if(x == y)
    {
        track(x, -1, kth);
        return;
    }

    ll pivot = f(x-1, y+1);
    if(y >= 0)
    {
        if(pivot >= kth)
        {
            cout << '(';
            track(x-1, y+1, kth);
        }
        else
        {
            cout << ')';
            if(y != 0) track(x-1, y-1, kth-pivot);
            else track(x-1, -1, kth-pivot);
        }
    }
    else
    {
        pivot = 1LL<<(x-1);
        if(pivot >= kth)
        {
            cout << '(';
            track(x-1, -1, kth);
        }
        else
        {
            cout << ')';
            track(x-1, -1, kth-pivot);
        }
    }
}

int main()
{
    onlycc;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    if(n&1)
    {
        if(1LL<<n < k+1) cout << -1;
        else track(n, -1, k+1);
    }
    else
    {
        if(f(n, 0) < k+1) cout << -1;
        else track(n, 0, k+1);
    }

    return 0;
}
