#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
    int n, k;
    int dp[10001];
    int coin[101];


    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++)
        scanf("%d", &coin[i]);

    for(int i = 1; i <= 10000; i++)
        dp[i] = INF;

    for(int i = 1; i <= n; i++)
    {
        for(int j = coin[i]; j <= k; j += coin[i])
        {
            if(dp[j] == INF)
                dp[j] = j / coin[i];
        }

        for(int j = coin[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
    }

    if(dp[k] != INF)
        printf("%d", dp[k]);

    else
        printf("-1");

    return 0;
}
