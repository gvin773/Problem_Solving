#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

typedef long long ll;

int t, n, ret;
int score[2][MAX], dp[MAX][3];

int maxv(int x, int s)
{
    if(x == n) return 0;
    if(dp[x][s] != -1) return dp[x][s];

    dp[x][s] = maxv(x+1, 0);
    if(s != 1) dp[x][s] = max(dp[x][s], maxv(x+1, 1) + score[0][x]);
    if(s != 2) dp[x][s] = max(dp[x][s], maxv(x+1, 2) + score[1][x]);

    return dp[x][s];
}

int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < 3; j++)
                dp[i][j] = -1;

        scanf("%d", &n);

        for(int j = 0; j < 2; j++)
            for(int k = 0; k < n; k++)
            {
                score[j][k] = 0;
                scanf("%d", &score[j][k]);
            }

        printf("%d\n", maxv(0, 0));
    }

    return 0;
}
