#include <iostream>
#include <algorithm>
using namespace std;

int L[21] = { 0 }; //-life
int J[21] = { 0 }; //+joy
int dp[21][101] = { 0 }; //dp[from 1st to nth][life] = joy

int main()
{
    int i, j, n;
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        scanf("%d", &L[i]);

    for(i = 1; i <= n; i++)
        scanf("%d", &J[i]);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j < 100; j++)
            dp[i][j] = dp[i-1][j];

        for(j = L[i]; j < 100; j++)
            dp[i][j] = max(dp[i][j], dp[i-1][j-L[i]]+J[i]);
    }

    printf("%d", dp[n][99]);

    return 0;
}
