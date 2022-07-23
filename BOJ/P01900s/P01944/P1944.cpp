#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, p[400000], num, cnt, ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string maze[55];
vector<ll> A, B;

int Find(int x)
{
    if(p[x] < 0) return x;
    p[x] = Find(p[x]);
    return p[x];
}

bool Merge(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px == py) return false;
    if(p[px] < p[py])
    {
        p[px] += p[py];
        p[py] = px;
    }
    else
    {
        p[py] += p[px];
        p[px] = py;
    }

    return true;
}

class Edge
{
public:
    int u, v, w;
    Edge(): Edge(-1, -1, 0){}
    Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
    bool operator <(const Edge& O) const { return w < O.w; }
};

Edge e[400000];

void bfs(int i, int j)
{
    bool visited[55][55] = {};
    int sx = A[i], sy = B[i], tx = A[j], ty = B[j];

    queue<pii> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int z = 0; z < Size; z++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x == tx && y == ty)
            {
                e[num++] = Edge(i, j, level);
                return;
            }

            for(int o = 0; o < 4; o++)
            {
                int nx = x+dx[o], ny = y+dy[o];
                if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && maze[nx][ny] != '1')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        level++;
    }
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> maze[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(maze[i][j] == 'S' || maze[i][j] == 'K')
            {
                A.push_back(i);
                B.push_back(j);
            }
        }
    }

    for(int i = 0; i < m+1; i++)
    {
        int temp = num;
        for(int j = 0; j < m+1; j++)
        {
            if(i == j) continue;
            bfs(i, j);
        }
        if(temp == num)
        {
            cout << -1;
            return 0;
        }
    }

    memset(p, -1, sizeof(p));
    sort(e, e+num);

    for(int i = 0; i < num; i++)
    {
        if(Merge(e[i].u, e[i].v))
        {
            ans += e[i].w;
            cnt++;
        }
        if(cnt == m) break;
    }
    sort(p, p+m+1);
    cout << (-p[0] == m+1 ? ans : -1);

    return 0;
}
