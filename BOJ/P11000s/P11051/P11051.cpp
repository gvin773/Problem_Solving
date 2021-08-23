#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int comb(int n, int k)
{
    if(dp[n][k] != 0) return dp[n][k];

    dp[n][k] = (comb(n-1, k-1) % 10007 + comb(n-1, k) % 10007) % 10007;
    return dp[n][k];
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 0; i <= 1000; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    printf("%d", comb(n, k));

    return 0;
}
