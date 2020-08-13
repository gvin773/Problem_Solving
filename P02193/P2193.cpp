#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, dp[91][2];

ll pn(ll l, ll d)
{
    if(dp[l][d] != -1) return dp[l][d];

    if(d == 0) dp[l][d] = pn(l-1, 0) + pn(l-1, 1);
    if(d == 1) dp[l][d] = pn(l-1, 0);

    return dp[l][d];
}

int main()
{
    for(int i = 1; i <= 90; i++)
        for(int j = 0; j < 2; j++)
            dp[i][j] = -1;

    dp[1][0] = 0, dp[1][1] = 1;
    scanf("%lld", &n);
    printf("%lld", pn(n, 0) + pn(n, 1));

    return 0;
}
