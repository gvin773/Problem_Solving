#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

struct tri
{
    int x, y, z;
};

int m, n, h, box[100][100][100], a[4] = {0, 0, 1, -1}, b[4] = {1, -1, 0, 0};
bool visited[100][100][100];
queue<tri> q;

int bfs()
{
    tri now = q.front();
    visited[now.x][now.y][now.z] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            now = q.front();
            q.pop();

            for(int j = 0; j < 4; j++)
            {
                int ny = now.y+a[j], nz = now.z+b[j];
                if(0 <= ny && ny < n && 0 <= nz && nz < m && !visited[now.x][ny][nz] && box[now.x][ny][nz] == 0)
                {
                    visited[now.x][ny][nz] = true;
                    box[now.x][ny][nz] = 1;
                    q.push({now.x, ny, nz});
                }
            }

            int nx = now.x + 1;
            if(0 <= nx && nx < h && !visited[nx][now.y][now.z] && box[nx][now.y][now.z] == 0)
            {
                visited[nx][now.y][now.z] = true;
                box[nx][now.y][now.z] = 1;
                q.push({nx, now.y, now.z});
            }

            nx = now.x - 1;
            if(0 <= nx && nx < h && !visited[nx][now.y][now.z] && box[nx][now.y][now.z] == 0)
            {
                visited[nx][now.y][now.z] = true;
                box[nx][now.y][now.z] = 1;
                q.push({nx, now.y, now.z});
            }
        }
        level++;
    }

    for(int i = 0; i < h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                if(box[i][j][k] == 0) return 0;
    return level;
}

int main()
{
    onlycc;
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++) for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) q.push({i, j, k});
            }
    cout << bfs()-1;

    return 0;
}
