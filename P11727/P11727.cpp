#include <iostream>
#include <algorithm>
#define MOD 10007
using namespace std;

typedef long long ll;

ll n, dp[1001][2];

ll f(int x, int d)
{
    if(dp[x][d] != -1) return dp[x][d];
    if(d == 0) dp[x][d] = (f(x-1, 0)%MOD + f(x-1, 1)%MOD) % MOD;
    if(d == 1) dp[x][d] = ((f(x-2, 0)%MOD + f(x-2, 1)%MOD)%MOD)*2 % MOD;

    return dp[x][d];
}

int main()
{
    for(int i = 1; i <= 1000; i++)
        dp[i][0] = dp[i][1] = -1;

    dp[1][0] = 1, dp[1][1] = 0, dp[2][0] = 1, dp[2][1] = 2;
    scanf("%lld", &n);
    printf("%lld", (f(n, 0)%MOD + f(n, 1)%MOD) % MOD);

    return 0;
}
