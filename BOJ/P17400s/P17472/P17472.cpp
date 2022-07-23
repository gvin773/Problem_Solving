#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, a[20][20], cnt, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, num, p[10], ans;
bool visited[20][20];
vector<pll> island[111];

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

void dfs(int x, int y)
{
    visited[x][y] = true;
    island[cnt].push_back({x, y});
    a[x][y] = cnt;

    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && a[nx][ny]) dfs(nx, ny);
    }
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && a[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    Edge e[10000];
    for(int i = 1; i <= cnt; i++)
    {
        for(auto pos : island[i])
        {
            for(int j = 0; j < 4; j++)
            {
                int nx = pos.first, ny = pos.second, len = 0;
                while(1)
                {
                    len++;
                    nx += dx[j], ny += dy[j];
                    if(!(0 <= nx && nx < n && 0 <= ny && ny < m)) break;
                    if(a[nx][ny]) break;
                }

                if(0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != 0 && a[nx][ny] != a[pos.first][pos.second] && len > 2) e[num++] = Edge(a[nx][ny]-1, a[pos.first][pos.second]-1, len-1);
            }
        }
    }

    memset(p, -1, sizeof(p));
    sort(e, e+num);

    ll ecnt = 0;
    for(int i = 0; i < num; i++)
    {
        if(Merge(e[i].u, e[i].v))
        {
            ans += e[i].w;
            ecnt++;
        }
        if(ecnt == cnt-1) break;
    }

    sort(p, p+cnt);
    cout << (-p[0] == cnt ? ans : -1);

    return 0;
}
