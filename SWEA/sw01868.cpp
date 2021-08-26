#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t, n, narr[300][300], dx[8] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, 1, -1, 1, -1}, ans;
string arr[300];
bool visited[300][300];

void get_narr(int x, int y)
{
    if(arr[x][y] == '*')
    {
        for(int i = 0; i < 8; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n) narr[nx][ny]++;
        }
    }
}

void dfs(int x, int y)
{
    if(visited[x][y]) return;

    visited[x][y] = true;
    if(narr[x][y] == 0)
    {
        for(int i = 0; i < 8; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        memset(narr, 0, sizeof(narr));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) get_narr(i, j);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            if(arr[i][j] == '*') narr[i][j] = -1;

        vector<pii> zero, block;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(narr[i][j] == 0) zero.push_back({i, j});
                else if(narr[i][j] > 0) block.push_back({i, j});
            }
        }

        ans = 0;
        memset(visited, 0, sizeof(visited));
        for(auto pos : zero)
        {
            if(!visited[pos.first][pos.second])
            {
                ans++;
                dfs(pos.first, pos.second);
            }
        }

        for(auto pos : block)
            if(!visited[pos.first][pos.second]) ans++;

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
