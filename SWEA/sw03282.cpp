#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int t, n, k, w[100], v[100], dp[100][100001];

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
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
        memset(dp, -1, sizeof(dp));
        cout << '#' << tc << ' ' << f(0, k) << '\n';
    }

    return 0;
}
