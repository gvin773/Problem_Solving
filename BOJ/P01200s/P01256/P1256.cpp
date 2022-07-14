#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, k, dp[501][501];

ll comb(int x, int y)
{
    if(x == y || y == 0) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = (comb(x-1, y-1) + comb(x-1, y) > 1000000000LL ? 1000000100LL : comb(x-1, y-1) + comb(x-1, y));
}

void track(ll x, ll y, ll kth)
{
    if(x > 0 && comb(x+y-1, y) >= kth)
    {
        cout << 'a';
        track(x-1, y, kth);
    }
    else if(y > 0)
    {
        cout << 'z';
        track(x, y-1, kth-comb(x+y-1, y));
    }
}

int main()
{
    onlycc;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    if(comb(n+m, n) < k) cout << -1;
    else track(n, m, k);

    return 0;
}
