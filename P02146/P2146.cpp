#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

int n, ans = 46464646, island[100][100], cnt, a[4] = {0, 0, 1, -1}, b[4] = {1, -1, 0, 0};
bool m[100][100], visited[100][100];
queue<pair<int, int>> q;

void dfs(int x, int y)
{
    visited[x][y] = true;
    island[x][y] = cnt;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+a[i], ny = y+b[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && m[nx][ny])
            dfs(nx, ny);
    }
}

int bfs(int x, int y)
{
    visited[x][y] = true;
    q.push({x, y});

    int level = 0, first = 1, color = island[x][y];
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            pair<int, int> now = q.front();
            if(island[now.first][now.second] != 0 && first != 1) return level;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = now.first+a[i], ny = now.second+b[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && (island[nx][ny] == 0 || island[nx][ny] != color))
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            first = 0;
        }
        level++;
    }

    return 46464646;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> m[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && m[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(m[i][j])
            {
                while(!q.empty()) q.pop();
                memset(visited, 0, sizeof(visited));
                ans = min(ans, bfs(i, j));
            }
        }
    }

    cout << ans-1;

    return 0;
}
