#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#define MAX 987654321
using namespace std;

typedef long long ll;

int n, X, Y, x[60], y[60], dp[60][201][201], ans, idx;

int main()
{
    onlycc;
    for(int i = 0; i < 60; i++)
        for(int j = 0; j < 200; j++)
            for(int k = 0; k < 200; k++)
                dp[i][j][k] = MAX;

    for(int i = 0; i < 60; i++) dp[i][0][0] = 0;

    cin >> n >> X >> Y;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    dp[0][x[0]][y[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            for(int k = 0; k < 200; k++)
            {
                dp[i][j][k] = dp[i-1][j][k];
                if(j >= x[i] && k >= y[i]) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-x[i]][k-y[i]] + 1);
            }
        }
    }

    ans = MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = X; j < 200; j++)
        {
            for(int k = Y; k < 200; k++)
            {
                if(dp[i][j][k] < ans)
                {
                    ans = dp[i][j][k];
                    idx = i+1;
                }
            }
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans << '\n' << idx;

    return 0;
}
