#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int tc, c, r, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ret;
pii s;
string maze[1100];
bool visited[1100][1100];

void dfs(pii k, int L)
{
    int x = k.first, y = k.second;
    visited[x][y] = true;

    bool flag = false;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if(0<=nx&&nx<r && 0<=ny&&ny<c && maze[nx][ny] == '.' && !visited[nx][ny])
        {
            flag = true;
            dfs({nx,ny}, L+1);
        }
    }

    if(!flag && L > ret)
    {
        ret = L;
        s = k;
    }
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> c >> r;
        for(int i = 0; i < r; i++) cin >> maze[i];

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(maze[i][j] == '.')
                {
                    s = {i, j};
                    goto xy;
                }
            }
        }
        xy: ret = 0;
        memset(visited, 0, sizeof(visited));
        dfs(s, 0);

        ret = 0;
        memset(visited, 0, sizeof(visited));
        dfs(s, 0);

        cout << "Maximum rope length is " << ret << ".\n";
    }

    return 0;
}
