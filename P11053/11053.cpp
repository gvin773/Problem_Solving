#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int seq[1001];

int main()
{
    int n, ret;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &seq[i]);

    for(int i = 1; i <= n; i++)
        dp[i] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(seq[j] > seq[i])
                dp[j] = max(dp[j], dp[i]+1);
        }
    }

    ret = dp[1];
    for(int i = 2; i <= n; i++)
        ret = max(ret, dp[i]);

    printf("%d", ret);

    return 0;
}
