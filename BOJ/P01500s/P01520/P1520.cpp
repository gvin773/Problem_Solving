#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll m, n, arr[500][500], dp[500][500], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

ll f(int a, int b)
{
    if(dp[a][b] != -1) return dp[a][b];

    ll &now = dp[a][b] = 0;
    for(int i = 0; i < 4; i++)
    {
        int x = a+dx[i], y = b+dy[i];
        if(0 <= x && x < m && 0 <= y && y < n && arr[a][b] > arr[x][y]) now += f(x, y);
    }
    return now;
}

int main()
{
    onlycc;
    memset(dp, -1, sizeof(dp));
    cin >> m >> n;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];
    dp[m-1][n-1] = 1;
    cout << f(0, 0);

    return 0;
}
