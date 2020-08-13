#include <iostream>
#include <algorithm>
#define MOD 15746
using namespace std;

typedef long long ll;

ll n, dp[1000001][2];

ll num(int x, int d)
{
    if(dp[x][d] != -1) return dp[x][d];
    if(d == 0) dp[x][d] = (num(x-1, 0)%MOD + num(x-1, 1)%MOD) % MOD;
    if(d == 1) dp[x][d] = (num(x-2, 0)%MOD + num(x-2, 1)%MOD) % MOD;

    return dp[x][d];
}

int main()
{
    for(int i = 1; i <= 1000000; i++)
        dp[i][0] = dp[i][1] = -1;

    dp[1][0] = 1, dp[1][1] = 0, dp[2][0] = 1, dp[2][1] = 1;
    scanf("%lld", &n);
    printf("%lld", (num(n, 0)%MOD + num(n, 1)%MOD) % MOD);

    return 0;
}
