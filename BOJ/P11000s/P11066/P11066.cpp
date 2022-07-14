#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tc, k, arr[500], psum[500], dp[500][500];

ll f(int a, int b)
{
    if(a >= b) return 0;
    if(dp[a][b] != -1) return dp[a][b];

    ll &now = dp[a][b] = LLONG_MAX;
    for(int i = a; i < b; i++) now = min(now, f(a, i) + f(i+1, b) + psum[i] - (a==0 ? 0 : psum[a-1]) + psum[b] - psum[i]);
    return now;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> k;
        for(int i = 0; i < k; i++) cin >> arr[i];
        for(int i = 0; i < k; i++) psum[i] = arr[i] + (i == 0 ? 0 : psum[i-1]);
        for(int i = 0; i < k-1; i++) dp[i][i+1] = arr[i]+arr[i+1];
        cout << f(0, k-1) << '\n';
    }

    return 0;
}
