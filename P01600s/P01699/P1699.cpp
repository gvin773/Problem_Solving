#include <iostream>
#include <algorithm>
#define IM 987654321
using namespace std;

typedef long long ll;

int n, dp[320][100001], num[320], cnt;

int main()
{
    for(int i = 0; i < 320; i++)
        for(int j = 0; j <= 100000; j++)
            dp[i][j] = IM;

    scanf("%d", &n);
    for(cnt = 1; cnt*cnt <= n; cnt++)
        num[cnt-1] = cnt*cnt;

    cnt--;

    for(int i = 0; i < cnt; i++)
    {
        dp[i][0] = 0;
        for(int j = 0; j <= n; j++)
        {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            int jj = j + num[i];
            if(jj <= n) dp[i][jj] = min(dp[i][jj], dp[i][j]+1);
        }
    }

    printf("%d", dp[cnt-1][n]);

    return 0;
}
