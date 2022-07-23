#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, w, x[1111], y[1111], dp[1111][1111], ans[1111][1111];

ll dist(int i, int j)
{
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}

ll f(int a, int b)
{
    if(a == w+1 || b == w+1) return 0;
    if(dp[a][b] != -1) return dp[a][b];

    ll &ret = dp[a][b];
    ret = f(max(a,b)+1, b) + dist(a, max(a,b)+1);
    ans[a][b] = 1;

    if(f(a, max(a,b)+1) + dist(b, max(a,b)+1) < ret)
    {
        ans[a][b] = 2;
        ret = f(a, max(a,b)+1) + dist(b, max(a,b)+1);
    }

    return ret;
}

void track(int a, int b)
{
    if(a == w+1 || b == w+1) return;

    cout << ans[a][b] << '\n';
    if(ans[a][b] == 1) track(max(a,b)+1, b);
    else track(a, max(a,b)+1);
}

int main()
{
    onlycc;
    cin >> n >> w;
    for(int i = 2; i < w+2; i++) cin >> x[i] >> y[i];
    memset(dp, -1, sizeof(dp));
    x[0] = y[0] = 1;
    x[1] = y[1] = n;

    cout << f(0, 1) << '\n';
    track(0, 1);

    return 0;
}
