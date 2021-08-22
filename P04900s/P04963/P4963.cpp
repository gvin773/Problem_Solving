#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int w, h, a[4] = {0, 0, 1, -1}, b[4] = {1, -1, 0, 0}, A[4] = {1, 1, -1, -1}, B[4] = {1, -1, 1, -1};

void dfs(int x, int y, bool visited[][50], int board[][50])
{
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+a[i], ny = y+b[i];
        if(0 <= nx && nx < h && 0 <= ny && ny < w && !visited[nx][ny] && board[nx][ny]) dfs(nx, ny, visited, board);
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x+A[i], ny = y+B[i];
        if(0 <= nx && nx < h && 0 <= ny && ny < w && !visited[nx][ny] && board[nx][ny]) dfs(nx, ny, visited, board);
    }
}

int main()
{
    onlycc;
    while(1)
    {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        int board[50][50], cnt = 0;
        bool visited[50][50] = {};
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> board[i][j];

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(!visited[i][j] && board[i][j])
                {
                    cnt++;
                    dfs(i, j, visited, board);
                }

        cout << cnt << '\n';
    }

    return 0;
}
