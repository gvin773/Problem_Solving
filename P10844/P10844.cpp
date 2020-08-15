#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

typedef long long ll;

ll N, dp[10][101], ret;

int f(int n, int k)
{
    if(k == 0) return 0;
    if(dp[n][k] != -1) return dp[n][k];

    int ret;
    if(n == 0) ret = f(n+1, k-1);
    else if(n == 9) ret = f(n-1, k-1);
    else ret = (f(n+1, k-1)%MOD + f(n-1, k-1)%MOD) % MOD;

    dp[n][k] = ret;

    return ret;
}

int main()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j <= 100; j++)
            dp[i][j] = -1;

    for(int i = 0; i < 10; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    scanf("%lld", &N);

    for(int i = 1; i <= 9; i++)
        ret = (ret + f(i, N)) % MOD;

    printf("%lld", ret);

    return 0;
}
