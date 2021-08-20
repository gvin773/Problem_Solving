#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
1. bfs로 시작점으로부터의 깊이 계산
*주의* 큐에 푸시하고 바로 visited = true를 안해주면 원소 중복으로 큐가 터질 수 있음
*/

string str[101];
int n, m, maze[101][101], level;
bool visited[101][101];
queue<pair<int, int>> q;

int bfs(int x, int y)
{
    q.push({x, y});

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            pair<int, int> now = q.front();
            if(now == make_pair(n, m)) return level;
            visited[now.first][now.second] = true;

            if(now.first != 1 && maze[now.first-1][now.second] == 1 && !visited[now.first-1][now.second])
            {
                q.push({now.first-1, now.second});
                visited[now.first-1][now.second] = true;
            }

            if(now.second != 1 && maze[now.first][now.second-1] == 1 && !visited[now.first][now.second-1])
            {
                q.push({now.first, now.second-1});
                visited[now.first][now.second-1] = true;
            }

            if(now.first != n && maze[now.first+1][now.second] == 1 && !visited[now.first+1][now.second])
            {
                q.push({now.first+1, now.second});
                visited[now.first+1][now.second] = true;
            }

            if(now.second != m && maze[now.first][now.second+1] == 1 && !visited[now.first][now.second+1])
            {
                q.push({now.first, now.second+1});
                visited[now.first][now.second+1] = true;
            }

            q.pop();
        }

        level++;
    }
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
            cin >> str[i];

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            maze[i][j+1] = str[i][j] - '0';

    cout << bfs(1, 1)+1;

    return 0;
}
