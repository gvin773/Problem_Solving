#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, k, X, Y, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, sets[2001][2001];
pii p[2001][2001];
queue<pii> q;
bool visited[2001][2001];

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
    cin >> n >> k;
    memset(sets, -1, sizeof(sets));
    for(int i = 0; i < k; i++)
    {
        cin >> X >> Y;
        q.push({X,Y});
        visited[X][Y] = true;
        for(int j = 0; j < 4; j++)
        {
            int nx = X+dx[j], ny = Y+dy[j];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= n && visited[nx][ny]) Merge({nx, ny}, {X, Y});
        }
    }
    if(sets[Find(q.front()).first][Find(q.front()).second] == -k)
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
                if(1 <= nx && nx <= n && 1 <= ny && ny <= n && Find(now) != Find({nx,ny}))
                {
                    if(!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        k++;
                    }
                    Merge(now, {nx,ny});
                    q.push({nx,ny});
                    if(-k == sets[Find(now).first][Find(now).second])
                    {
                           cout << level+1;
                           return 0;
                    }

                    for(int j = 0; j < 4; j++)
                    {
                        int nnx = nx+dx[j], nny = ny+dy[j];
                        if(1 <= nnx && nnx <= n && 1 <= nny && nny <= n && visited[nnx][nny])
                        {
                            Merge({nx,ny}, {nnx,nny});
                            if(-k == sets[Find(now).first][Find(now).second])
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
