#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, k, x, a[100], b, ans;
bool dp[88][88][16161];

int main()
{
    onlycc;
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) cin >> a[i] >> b;

    for(int i = 0; i < n; i++) dp[i][1][a[i]] = true;
    for(int i = 0; i < n; i++) dp[i][0][0] = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= i+1; j++)
        {
            for(int s = 0; s <= n*x; s++)
            {
                if(dp[i][j][s] && i+1 < n) dp[i+1][j][s] = true;
                if(dp[i][j][s] && i+1 < n && j+1 <= k && s+a[i] <= n*x) dp[i+1][j+1][s+a[i+1]] = true;
            }
        }
    }
    for(int s = 0; s <= n*x; s++) if(dp[n-1][k][s]) ans = max(ans, s*(k*x-s));
    cout << ans;

    return 0;
}
