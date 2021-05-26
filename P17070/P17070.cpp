#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, home[17][17];
int dp[17][17][3]; //0: -, 1: |, 2: \

int dfs(int x, int y, int state)
{
    if(dp[x][y][state] != 0) return dp[x][y][state];
    if(x == n && y == n) return 0;

    int &ret = dp[x][y][state];
    if(state == 0)
    {
        if(y+1 <= n && home[x][y+1] == 0)
        {
            ret += dfs(x, y+1, 0);
            if(x+1 <= n && home[x+1][y] == 0 && home[x+1][y+1] == 0) ret += dfs(x+1, y+1, 2);
        }
    }

    if(state == 1)
    {
        if(x+1 <= n && home[x+1][y] == 0)
        {
            ret += dfs(x+1, y, 1);
            if(y+1 <= n && home[x][y+1] == 0 && home[x+1][y+1] == 0) ret += dfs(x+1, y+1, 2);
        }
    }

    if(state == 2)
    {
        if(y+1 <= n && x+1 <= n && home[x+1][y] == 0 && home[x][y+1] == 0 && home[x+1][y+1] == 0) ret += dfs(x+1, y+1, 2);
        if(y+1 <= n && home[x][y+1] == 0) ret += dfs(x, y+1, 0);
        if(x+1 <= n && home[x+1][y] == 0) ret += dfs(x+1, y, 1);
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> home[i][j];

    if(home[n][n] == 0 && home[n][n-1] == 0) dp[n][n][0] = 1;
    if(home[n][n] == 0 && home[n-1][n] == 0) dp[n][n][1] = 1;
    if(home[n][n] == 0 && home[n-1][n-1] == 0) dp[n][n][2] = 1;
    cout << dfs(1, 2, 0);

    return 0;
}
