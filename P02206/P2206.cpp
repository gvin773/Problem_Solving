#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
벽을 파괴 가능한 bfs, 벽을 파괴했는지 여부를 저장하면 해결할 수 있다.
*/

int n, m;
string graph[1001];
bool visited[1001][1001][2];
queue<pair<pair<int, int>, bool>> q;

int bfs()
{
    q.push({{1, 1}, true});
    visited[1][1][1] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0 ; i < Size; i++)
        {
            pair<pair<int, int>, bool> now = q.front();
            if(now.first == make_pair(n, m)) return level;
            q.pop();

            if(now.first.first != 1 && !visited[now.first.first-1][now.first.second][now.second])
            {
                if(graph[now.first.first-1][now.first.second] == '0')
                {
                    q.push({{now.first.first-1, now.first.second}, now.second});
                    visited[now.first.first-1][now.first.second][now.second] = true;
                }

                else if(now.second == true)
                {
                    q.push({{now.first.first-1, now.first.second}, !now.second});
                    visited[now.first.first-1][now.first.second][!now.second] = true;
                }
            }

            if(now.first.second != 1 && !visited[now.first.first][now.first.second-1][now.second])
            {
                if(graph[now.first.first][now.first.second-1] == '0')
                {
                    q.push({{now.first.first, now.first.second-1}, now.second});
                    visited[now.first.first][now.first.second-1][now.second] = true;
                }

                else if(now.second == true)
                {
                    q.push({{now.first.first, now.first.second-1}, !now.second});
                    visited[now.first.first][now.first.second-1][!now.second] = true;
                }
            }

            if(now.first.first != n && !visited[now.first.first+1][now.first.second][now.second])
            {
                if(graph[now.first.first+1][now.first.second] == '0')
                {
                    q.push({{now.first.first+1, now.first.second}, now.second});
                    visited[now.first.first+1][now.first.second][now.second] = true;
                }

                else if(now.second == true)
                {
                    q.push({{now.first.first+1, now.first.second}, !now.second});
                    visited[now.first.first+1][now.first.second][!now.second] = true;
                }
            }

            if(now.first.second != m && !visited[now.first.first][now.first.second+1][now.second])
            {
                if(graph[now.first.first][now.first.second+1] == '0')
                {
                    q.push({{now.first.first, now.first.second+1}, now.second});
                    visited[now.first.first][now.first.second+1][now.second] = true;
                }

                else if(now.second == true)
                {
                    q.push({{now.first.first, now.first.second+1}, !now.second});
                    visited[now.first.first][now.first.second+1][!now.second] = true;
                }
            }
        }

        level++;
    }

    return -2;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        graph[i] = "x" + temp;
    }
    cout << bfs()+1;
    return 0;
}
