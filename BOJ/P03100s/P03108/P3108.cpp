#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
도형을 보드에 그리고, 각 점을 dfs로 탐색하며 총 몇번만에 그릴 수 있는지 구한다.
이때, 서로 다른 도형에 있는 점과 점의 거리가 1인 경우, 한번에 그릴 수 없음에도
한번에 그릴 수 있는 것으로 카운트되므로, 이를 막기 위해 좌표계를 바꾸어준다.
또, (0,0)이 그려진 상태면 PU없이 그릴 수 있으므로, -1을 해준다.
*/

int n, x1, y1, x2, y2, nx1, ny1, nx2, ny2, ans, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool board[2001][2001], visited[2001][2001];

void dfs(int x, int y)
{
    if(x < 0 || x > 2000 || y < 0 || y > 2000) return;

    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
        if(board[x+dx[i]][y+dy[i]] && !visited[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i]);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        nx1 = (x1+500)*2, ny1 = (y1+500)*2;
        nx2 = (x2+500)*2, ny2 = (y2+500)*2;

        for(int i = nx1; i <= nx2; i++)
        {
            board[i][ny1] = true;
            board[i][ny2] = true;
        }
        for(int i = ny1; i <= ny2; i++)
        {
            board[nx1][i] = true;
            board[nx2][i] = true;
        }
    }

    for(int i = 0; i < 2001; i++)
    {
        for(int j = 0; j < 2001; j++)
        {
            if(!visited[i][j] && board[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    if(board[1000][1000]) ans--;

    cout << ans;

    return 0;
}
