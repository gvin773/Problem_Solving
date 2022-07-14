#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k, a[200], dp[10001];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    dp[0] = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j <= k; j++)
        if(j >= a[i]) dp[j] = dp[j] + dp[j-a[i]];
    cout << dp[k];

    return 0;
}
