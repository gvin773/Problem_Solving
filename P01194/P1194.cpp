#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, m, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string maze[50];
bool visited[50][50][1<<6];
queue<pair<pair<int, int>, int>> q;

int bfs(int sx, int sy)
{
    q.push({{sx, sy}, 0});
    visited[sx][sy][0] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int cx = q.front().first.first;
            int cy = q.front().first.second;
            int cstate = q.front().second;
            q.pop();

            if(maze[cx][cy] == '1') return level;

            for(int j = 0; j < 4; j++)
            {
                int nx = cx+dx[j], ny = cy+dy[j], state = cstate;
                if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny][state] && maze[nx][ny] != '#')
                {
                    if('a' <= maze[nx][ny] && maze[nx][ny] <= 'f')
                    {
                        state |= (1<<(maze[nx][ny]-'a'));
                        visited[nx][ny][state] = true;
                        q.push({{nx, ny}, state});
                    }

                    else if('A' <= maze[nx][ny] && maze[nx][ny] <= 'F' && ((state>>(maze[nx][ny]-'A')) & 1))
                    {
                        visited[nx][ny][state] = true;
                        q.push({{nx, ny}, state});
                    }

                    else if(maze[nx][ny] == '.' || maze[nx][ny] == '0' || maze[nx][ny] == '1')
                    {
                        visited[nx][ny][state] = true;
                        q.push({{nx, ny}, state});
                    }
                }
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> maze[i];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        if(maze[i][j] == '0') cout << bfs(i, j);

    return 0;
}
