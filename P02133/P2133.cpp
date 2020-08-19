#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int dp[31], n;

int main()
{
    onlycc;
    cin >> n;

    if(n%2 == 1)
    {
        cout << 0;
        return 0;
    }

    dp[2] = 3, dp[4] = 11;
    for(int i = 6; i <= n; i += 2)
    {
        dp[i] += dp[2] * dp[i-2];
        for(int j = 4; j < i; j +=2)
            dp[i] += 2 * dp[i-j];

        dp[i] += 2;
    }

    cout << dp[n];

    return 0;
}
