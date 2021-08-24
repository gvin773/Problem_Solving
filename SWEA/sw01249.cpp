#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

int t, n, dp[100][100], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string arr[100];
bool visited[100][100];

void bfs()
{
    queue<pair<int, int>> q;

    visited[0][0] = true;
    dp[0][0] = 0;
    q.push({0, 0});

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if(!visited[nx][ny] || dp[nx][ny] > dp[x][y]+arr[nx][ny]-'0')
                {
                    visited[nx][ny] = true;
                    dp[nx][ny] = dp[x][y] + arr[nx][ny] - '0';
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        bfs();
        cout << '#' << tc << ' ' << dp[n-1][n-1] << '\n';
    }

    return 0;
}
