#include <iostream>
#include <algorithm>
#define MOD 10007
using namespace std;

typedef long long ll;

ll N, dp[10][1001], ret;

int f(int n, int k)
{
    if(k == 0) return 0;
    if(dp[n][k] != -1) return dp[n][k];

    int ret = 0;
    if(n == 9) ret = f(n, k-1) % MOD;
    else
    {
        for(int i = 0; n+i <= 9; i++)
            ret = (ret%MOD + f(n+i, k-1)%MOD) % MOD;
    }

    dp[n][k] = ret;

    return ret;
}

int main()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j <= 1000; j++)
            dp[i][j] = -1;

    for(int i = 0; i < 10; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    scanf("%lld", &N);

    for(int i = 0; i <= 9; i++)
        ret = (ret + f(i, N)) % MOD;

    printf("%lld", ret);

    return 0;
}
