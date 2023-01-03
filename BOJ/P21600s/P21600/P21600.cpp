#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[100000], dp[100000], ans;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) dp[i] = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > dp[i-1]) dp[i] = dp[i-1]+1;
        else dp[i] = a[i];
    }
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}
