#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, cage[140][140], ans;
bool visited[140][140], edge[140][140][140][140];

void dfs(int x, int y, int cnt, int type)
{
    if(cnt > n) return;
    if(visited[x][y])
    {
        if(cnt == n) ans++;
        return;
    }

    visited[x][y] = true;
    if(type)
    {
        int nx = x-1, ny = y+1;
        if(!edge[x][y][nx][ny] && !edge[nx][ny][x][y])
        {
            edge[x][y][nx][ny] = true;
            edge[nx][ny][x][y] = true;
            dfs(nx, ny, cnt+1, 0);
            edge[x][y][nx][ny] = false;
            edge[nx][ny][x][y] = false;
        }

        nx = x+1, ny = y+1;
        if(!edge[x][y][nx][ny] && !edge[nx][ny][x][y])
        {
            edge[x][y][nx][ny] = true;
            edge[nx][ny][x][y] = true;
            dfs(nx, ny, cnt+1, 0);
            edge[x][y][nx][ny] = false;
            edge[nx][ny][x][y] = false;
        }

        nx = x, ny = y-2;
        if(!edge[x][y][nx][ny] && !edge[nx][ny][x][y])
        {
            edge[x][y][nx][ny] = true;
            edge[nx][ny][x][y] = true;
            dfs(nx, ny, cnt+1, 0);
            edge[x][y][nx][ny] = false;
            edge[nx][ny][x][y] = false;
        }
    }
    else
    {
        int nx = x-1, ny = y-1;
        if(!edge[x][y][nx][ny] && !edge[nx][ny][x][y])
        {
            edge[x][y][nx][ny] = true;
            edge[nx][ny][x][y] = true;
            dfs(nx, ny, cnt+1, 1);
            edge[x][y][nx][ny] = false;
            edge[nx][ny][x][y] = false;
        }

        nx = x+1, ny = y-1;
        if(!edge[x][y][nx][ny] && !edge[nx][ny][x][y])
        {
            edge[x][y][nx][ny] = true;
            edge[nx][ny][x][y] = true;
            dfs(nx, ny, cnt+1, 1);
            edge[x][y][nx][ny] = false;
            edge[nx][ny][x][y] = false;
        }

        nx = x, ny = y+2;
        if(!edge[x][y][nx][ny] && !edge[nx][ny][x][y])
        {
            edge[x][y][nx][ny] = true;
            edge[nx][ny][x][y] = true;
            dfs(nx, ny, cnt+1, 1);
            edge[x][y][nx][ny] = false;
            edge[nx][ny][x][y] = false;
        }
    }
    visited[x][y] = false;
}

int main()
{
    onlycc;
    cin >> n;
    visited[70][70] = true;
    dfs(70, 72, 0, 1);
    cout << (n == 1 ? 0 : ans);

    return 0;
}
