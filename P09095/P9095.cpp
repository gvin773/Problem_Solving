#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, dp[11] = {0, 1, 2, 4, };

int main()
{
    onlycc;
    int t;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 4; j <= n; j++)
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];

        cout << dp[n] << '\n';
    }

    return 0;
}
