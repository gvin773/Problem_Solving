#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, }, t, n;

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i ++)
    {
        cin >> n;

        if(dp[n] != 0)
        {
            cout << dp[n] << "\n";
            continue;
        }

        for(int j = 11; j <= n; j++)
            dp[j] = dp[j-1] + dp[j-5];

        cout << dp[n] << '\n';
    }

    return 0;
}
