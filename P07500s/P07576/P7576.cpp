#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, m, tom[1000][1000], x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0}, level, cnt;
bool visited[1000][1000];
queue<pair<int, int>> q;

void bfs()
{
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            pair<int, int> now = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                pair<int, int> next = {now.first+x[i], now.second+y[i]};
                if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < m)
                {
                    if(tom[next.first][next.second] == 0 && !visited[next.first][next.second])
                    {
                        q.push({next.first, next.second});
                        visited[next.first][next.second] = true;
                        tom[next.first][next.second] = 1;
                    }
                }
            }
        }

        level++;
    }
}

int main()
{
    onlycc;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> tom[i][j];
            if(tom[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }

    bfs();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(tom[i][j] == 0) cnt = 1;

    if(cnt) cout << -1;
    else cout << level-1;

    return 0;
}
