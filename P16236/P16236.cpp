#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int n, sea[20][20], fish = 2, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}, ans;
bool visited[20][20];
pair<int, int> s;
queue<pair<int ,int>> q;

pair<int, int> bfs()
{
    q.push(s);
    visited[s.first][s.second] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        vector<pair<int, int>> v;

        for(int i = 0; i < Size; i++)
        {
            pair<int, int> now = q.front();
            q.pop();

            for(int j = 0; j < 4; j++)
            {
                int nx = now.first+dx[j], ny = now.second+dy[j];
                if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny])
                {
                    if(sea[nx][ny] == 0 || sea[nx][ny] == fish)
                    {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                    else if(fish > sea[nx][ny])
                    {
                        v.push_back({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        level++;
        if(!v.empty())
        {
            ans += level;
            sort(v.begin(), v.end());
            return v.front();
        }
    }

    return {-46, -46};
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> sea[i][j];
            if(sea[i][j] == 9)
            {
                s = {i, j};
                sea[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    pair<int, int> target;
    while((target = bfs()) != make_pair(-46, -46))
    {
        memset(visited, 0, sizeof(visited));
        while(!q.empty()) q.pop();
        s = target;
        sea[s.first][s.second] = 0;
        cnt++;
        if(cnt == fish)
        {
            cnt = 0;
            fish++;
        }
    }

    cout << ans;

    return 0;
}
