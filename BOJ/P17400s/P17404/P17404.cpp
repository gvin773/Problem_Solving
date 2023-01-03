#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, rgb[1000][3], dp[1000][3], init = -1;

ll check(ll start, ll color, ll first)
{
    if(init != first)
    {
        memset(dp, 0, sizeof(dp));
        init = first;
    }

    if(dp[start][color] != 0) return dp[start][color];
    if(start == n-1) return dp[start][color] = (first != color ? rgb[start][color] : INT_MAX);

    ll ret = rgb[start][color];
    if(color == 0) ret = min(ret + check(start+1, 1, first), ret + check(start+1, 2, first));
    else if(color == 1) ret = min(ret + check(start+1, 0, first), ret + check(start+1, 2, first));
    else if(color == 2) ret = min(ret + check(start+1, 0, first), ret + check(start+1, 1, first));

    return dp[start][color] = ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> rgb[i][j];
    cout << min({check(0, 0, 0), check(0, 1, 1), check(0, 2, 2)});

    return 0;
}
