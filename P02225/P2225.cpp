#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

typedef long long ll;

ll dp[201][201];

ll check(int n, int k)
{
    if(dp[n][k] != -1) return dp[n][k];
    if(k == 1) return dp[n][k] = 1;

    ll ret = 0;
    for(int i = 0; i <= n; i++)
    {
        ret = (ret%MOD + check(n-i, k-1)%MOD) % MOD;
    }

    return dp[n][k] = ret;
}

int main()
{
    for(int i = 0; i <= 200; i++)
        for(int j = 0; j <= 200; j++)
            dp[i][j] = -1;

    onlycc;
    int n, k;
    cin >> n >> k;

    cout << check(n, k);

    return 0;
}
