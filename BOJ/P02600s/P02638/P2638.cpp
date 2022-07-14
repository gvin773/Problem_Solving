#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, a[150][150], num[150][150], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool visited[150][150], used[150][150];
queue<pii> q;

void dfs(int x, int y)
{
    if(visited[x][y]) return;

    visited[x][y] = true;
    a[x][y] = 2;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny])
        {
            if(a[nx][ny] == 0) dfs(nx, ny);
            if(a[nx][ny] == 1)
            {
                num[nx][ny]++;
                if(num[nx][ny] >= 2)
                {
                    used[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

    dfs(0, 0);
    dfs(0, m-1);
    dfs(n-1, 0);
    dfs(n-1, m-1);

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            dfs(x, y);
        }

        level++;
    }
    cout << level;

    return 0;
}
