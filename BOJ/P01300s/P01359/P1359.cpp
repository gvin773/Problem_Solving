#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k, s, dp[20];

ll fac(int n)
{
    if(dp[n] != -1) return dp[n];
    if(n == 0 || n == 1) return 1;
    return dp[n] = n*fac(n-1);
}

ll C(int n, int k)
{
    if(n < k) return 0;
    return fac(n)/(fac(k) * fac(n-k));
}

int main()
{
    onlycc;
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for(int i = k; i <= m; i++) s += C(m, i) * C(n-m, m-i);
    cout.precision(10);
    cout << s / (double)C(n, m);

    return 0;
}
