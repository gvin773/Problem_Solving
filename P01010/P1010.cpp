#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

ll t, n, m, dp[30][30];

int solve(int x, int y)
{
    if(x == y || y == 0) return 1;
    else if(y < 0 || x < y) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = (solve(x-1, y-1) + solve(x-1, y));

    return dp[x][y] = ans;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        cout << solve(m, n) << '\n';
    }

    return 0;
}
