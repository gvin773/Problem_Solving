#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll r, c, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, cnt, sets[1500][1500];
string water[1500];
pii L[2], p[2001][2001];
queue<pii> q;

pii Find(pii x)
{
    if(p[x.first][x.second] == make_pair(0,0)) return x;
    p[x.first][x.second] = Find(p[x.first][x.second]);
    return p[x.first][x.second];
}

void Merge(pii x, pii y)
{
    pii px = Find(x);
    pii py = Find(y);
    if(px == py) return;
    if(sets[px.first][px.second] <= sets[py.first][py.second])
    {
        sets[px.first][px.second] += sets[py.first][py.second];
        p[py.first][py.second] = px;
    }
    else
    {
        sets[py.first][py.second] += sets[px.first][px.second];
        p[px.first][px.second] = py;
    }
}

int main()
{
    onlycc;
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> water[i];

    memset(sets, -1, sizeof(sets));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(water[i][j] == '.' || water[i][j] == 'L')
            {
                q.push({i,j});
                for(int k = 0; k < 4; k++)
                {
                    int nx = i+dx[k], ny = j+dy[k];
                    if(0 <= nx && nx < r && 0 <= ny && ny < c && water[nx][ny] == '.') Merge({nx,ny}, {i,j});
                }
            }
            if(water[i][j] == 'L') L[cnt++] = {i,j};
        }
    }
    if(Find(L[0]) == Find(L[1]))
    {
        cout << 0;
        return 0;
    }

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0 ; s < Size; s++)
        {
            pii now = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = now.first+dx[i], ny = now.second+dy[i];
                if(0 <= nx && nx < r && 0 <= ny && ny < c && (water[nx][ny] == 'L' || water[nx][ny] == 'X') && Find(now) != Find({nx,ny}))
                {
                    if(water[nx][ny] != 'L') water[nx][ny] = '.';
                    Merge(now, {nx,ny});
                    if(Find(L[0]) == Find(L[1]))
                    {
                        cout << level+1;
                        return 0;
                    }
                    q.push({nx,ny});

                    for(int j = 0; j < 4; j++)
                    {
                        int nnx = nx+dx[j], nny = ny+dy[j];
                        if(0 <= nnx && nnx < r && 0 <= nny && nny < c && water[nnx][nny] == '.')
                        {
                            Merge({nnx,nny}, {nx,ny});
                            if(Find(L[0]) == Find(L[1]))
                            {
                                cout << level+1;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        level++;
    }

    return 0;
}
