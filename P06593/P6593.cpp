#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
평범한 bfs 문제로, 동서남북상하 6개의 방향으로 bfs를 해주면 된다.
*주의* 입력시 변수 초기화 해줄 것
*/

int l, r, c, ans;
pair<int, int> start, fin;

int bfs(bool visited[][30], queue<pair<int, int>> &q, string building[])
{
    q.push(start);
    visited[start.first][start.second] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            pair<int, int> now = q.front();
            if(now == fin) return level;

            q.pop();

            if(now.first%r != 0 && !visited[now.first-1][now.second] && (building[now.first-1][now.second] == '.' || fin == make_pair(now.first-1, now.second)))
            {
                q.push({now.first-1, now.second});
                visited[now.first-1][now.second] = true;
            }

            if(now.second != 0 && !visited[now.first][now.second-1] && (building[now.first][now.second-1] == '.' || fin == make_pair(now.first, now.second-1)))
            {
                q.push({now.first, now.second-1});
                visited[now.first][now.second-1] = true;
            }

            if(now.first%r != r-1 && !visited[now.first+1][now.second] && (building[now.first+1][now.second] == '.' || fin == make_pair(now.first+1, now.second)))
            {
                q.push({now.first+1, now.second});
                visited[now.first+1][now.second] = true;
            }

            if(now.second != c-1 && !visited[now.first][now.second+1] && (building[now.first][now.second+1] == '.' || fin == make_pair(now.first, now.second+1)))
            {
                q.push({now.first, now.second+1});
                visited[now.first][now.second+1] = true;
            }

            if(now.first >= r && !visited[now.first-r][now.second] && (building[now.first-r][now.second] == '.' || fin == make_pair(now.first-r, now.second)))
            {
                q.push({now.first-r, now.second});
                visited[now.first-r][now.second] = true;
            }

            if(now.first < (l-1)*r && !visited[now.first+r][now.second] && (building[now.first+r][now.second] == '.' || fin == make_pair(now.first+r, now.second)))
            {
                q.push({now.first+r, now.second});
                visited[now.first+r][now.second] = true;
            }
        }

        level++;
    }

    return 46464646;
}

int main()
{
    onlycc;
    while(1)
    {
        cin >> l >> r >> c;
        if(l == r && r == c && c == 0) break;

        string building[900];
        for(int i = 0; i < l*r; i++)
            cin >> building[i];

        for(int i = 0; i < l*r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(building[i][j] == 'S')
                    start = {i, j};

                if(building[i][j] == 'E')
                    fin = {i, j};
            }
        }

        bool visited[900][30] = {};
        queue<pair<int, int>> q;
        if((ans = bfs(visited, q, building)) != 46464646) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}
