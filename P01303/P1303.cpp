#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, B, W, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string board[100];
bool visited[100][100];

int dfs(int i, int j)
{
    if(visited[i][j]) return 0;
    visited[i][j] = true;

    int ret = 1;
    for(int t = 0; t < 4; t++)
    {
        int x = i+dx[t], y = j+dy[t];
        if(0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && board[i][j] == board[x][y]) ret += dfs(x, y);
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> board[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int num = dfs(i, j);
            if(board[i][j] == 'W') W += num*num;
            else B += num*num;
        }
    }

    cout << W << ' ' << B;

    return 0;
}
