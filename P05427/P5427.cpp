#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

/*
bfs 이용함
일반적인 bfs 문제와의 차이점이 불이 움직인다는 것
따라서 fire에 대해서도 queue를 활용하여 bfs를 수행해주면 됨
*/

int t, w, h, ans;
pair<int, int> start;
string building[1000];
bool visited[1000][1000], fvisited[1000][1000];
queue<pair<int, int>> p, fire;

bool possible(pair<int, int> now, int dir)
{
    if(dir == 0) now = make_pair(now.first-1, now.second);
    else if(dir == 1) now = make_pair(now.first, now.second-1);
    else if(dir == 2) now = make_pair(now.first+1, now.second);
    else now = make_pair(now.first, now.second+1);

    if(!(now.first >= 0 && now.first < h) || !(now.second >= 0 && now.second < w)) return false;
    if(building[now.first][now.second] != '.') return false;

    if(now.first != 0 && building[now.first-1][now.second] == '*') return false;
    if(now.second != 0 && building[now.first][now.second-1] == '*') return false;
    if(now.first+1 != h && building[now.first+1][now.second] == '*') return false;
    if(now.second+1 != w && building[now.first][now.second+1] == '*') return false;

    return true;
}

int bfs()
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(building[i][j] == '*')
            {
                fire.push({i, j});
                fvisited[i][j] = true;
            }
        }
    }

    p.push(start);
    visited[start.first][start.second] = true;

    int level = 0;
    while(!p.empty())
    {
        int Size = p.size();
        for(int i = 0; i < Size; i++)
        {
            pair<int, int> now = p.front();
            p.pop();
            if((building[now.first][now.second] == '.' || building[now.first][now.second] == '@') && (now.first == 0 || now.second == 0 || now.first+1 == h || now.second+1 == w)) return level;

            if(now.first != 0 && !visited[now.first-1][now.second] && possible(now, 0))
            {
                p.push({now.first-1, now.second});
                visited[now.first-1][now.second] = true;
            }

            if(now.second != 0 && !visited[now.first][now.second-1] && possible(now, 1))
            {
                p.push({now.first, now.second-1});
                visited[now.first][now.second-1] = true;
            }

            if(now.first+1 != h && !visited[now.first+1][now.second] && possible(now, 2))
            {
                p.push({now.first+1, now.second});
                visited[now.first+1][now.second] = true;
            }

            if(now.second+1 != w && !visited[now.first][now.second+1] && possible(now, 3))
            {
                p.push({now.first, now.second+1});
                visited[now.first][now.second+1] = true;
            }
        }

        int fSize = fire.size();
        if(fSize != 0)
        {
            for(int i = 0; i < fSize; i++)
            {
                pair<int, int> fnow = fire.front();
                fire.pop();

                if(fnow.first != 0 && !fvisited[fnow.first-1][fnow.second] && building[fnow.first-1][fnow.second] != '#')
                {
                    fire.push({fnow.first-1, fnow.second});
                    fvisited[fnow.first-1][fnow.second] = true;
                    building[fnow.first-1][fnow.second] = '*';
                }

                if(fnow.second != 0 && !fvisited[fnow.first][fnow.second-1] && building[fnow.first][fnow.second-1] != '#')
                {
                    fire.push({fnow.first, fnow.second-1});
                    fvisited[fnow.first][fnow.second-1] = true;
                    building[fnow.first][fnow.second-1] = '*';
                }

                if(fnow.first+1 != h && !fvisited[fnow.first+1][fnow.second] && building[fnow.first+1][fnow.second] != '#')
                {
                    fire.push({fnow.first+1, fnow.second});
                    fvisited[fnow.first+1][fnow.second] = true;
                    building[fnow.first+1][fnow.second] = '*';
                }

                if(fnow.second+1 != w && !fvisited[fnow.first][fnow.second+1] && building[fnow.first][fnow.second+1] != '#')
                {
                    fire.push({fnow.first, fnow.second+1});
                    fvisited[fnow.first][fnow.second+1] = true;
                    building[fnow.first][fnow.second+1] = '*';
                }
            }
        }

        level++;
    }

    return 46464646;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> w >> h;
        for(int j = 0; j < h; j++)
            cin >> building[j];

        for(int j = 0; j < h; j++)
        {
            for(int k = 0; k < w; k++)
            {
                if(building[j][k] == '@')
                    start = {j, k};
            }
        }

        while(!p.empty()) p.pop();
        while(!fire.empty()) fire.pop();
        memset(visited, 0, sizeof(visited));
        memset(fvisited, 0, sizeof(fvisited));

        if((ans = bfs()) != 46464646) cout << ans+1 << '\n';
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}
