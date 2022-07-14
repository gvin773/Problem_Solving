#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, l, i, dp[50][50], ans[50];

ll number(int x, int y)
{
    if(dp[x][y] != -1) return dp[x][y];
    if(x == 0 || y == 0) return dp[x][y] = 1;

    ll &ret = dp[x][y];
    return ret = number(x-1, y) + number(x-1, y-1);
}

void track(int x, int y, int k)
{
    if(x == 0 || y == 0) return;

    ll pivot = number(x-1, y);
    if(pivot <= k)
    {
        ans[x] = 1;
        track(x-1, y-1, k-pivot);
    }
    else track(x-1, y, k);
}

int main()
{
    onlycc;
    cin >> n >> l >> i;
    memset(dp, -1, sizeof(dp));
    number(n, l);
    track(n, l, i-1);
    for(int i = n; i >= 1; i--) cout << ans[i];

    return 0;
}
