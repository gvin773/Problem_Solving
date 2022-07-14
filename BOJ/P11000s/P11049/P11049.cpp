#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, r[500], c[500], dp[500][500];

ll f(int a, int b)
{
    if(a == b) return 0;
    if(dp[a][b] != -1) return dp[a][b];

    ll &now = dp[a][b] = LLONG_MAX;
    for(int i = a; i < b; i++) now = min(now, f(a, i) + r[a]*c[i]*c[b] + f(i+1, b));

    return now;
}

int main()
{
    onlycc;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> r[i] >> c[i];
    for(int i = 0; i < n-1; i++)
    {
        dp[i][i+1] = r[i]*c[i]*c[i+1];
    }
    cout << f(0, n-1);

    return 0;
}
