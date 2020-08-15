#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, price[1000], dp[1000][1000];

int maxp(int n, int k)
{
    if(n == N) return 0;
    if(dp[n][k] != -1) return dp[n][k];

    int ret = maxp(n+1, k);
    if(k >= n+1) ret = max(ret, maxp(n, k-(n+1))+price[n]);
    dp[n][k] = ret;

    return ret;
}

int main()
{
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            dp[i][j] = -1;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", price+i);

    printf("%d", maxp(0, N));

    return 0;
}
