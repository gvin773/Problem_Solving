#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, k, w[100], v[100], dp[100][100001];

int f(int i, int K)
{
    if(i == n) return 0;
    if(dp[i][K] != -1) return dp[i][K];

    dp[i][K] = 0;
    int ret = f(i+1, K);
    if(K >= w[i]) ret = max(ret, f(i+1, K-w[i]) + v[i]);
    dp[i][K] = ret;

    return ret;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d%d", w+i, v+i);

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 100000; j++)
            dp[i][j] = -1;

    printf("%d", f(0, k));

    return 0;
}
