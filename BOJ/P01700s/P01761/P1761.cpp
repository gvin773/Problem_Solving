#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 40101;
ll n, m, a, b, c, p[SIZE][20], depth[SIZE], dist[SIZE][20];
vector<pii> Edge[SIZE];

void init(int now)
{
    for(auto next : Edge[now])
    {
        if(depth[next.first] == -1)
        {
            depth[next.first] = depth[now] + 1;
            p[next.first][0] = now;
            dist[next.first][0] = next.second;
            init(next.first);
        }
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        Edge[a].push_back({b, c});
        Edge[b].push_back({a, c});
    }

    memset(p, -1, sizeof(p));
    memset(depth, -1, sizeof(depth));
    memset(dist, 0, sizeof(dist));
    depth[1] = 0;
    init(1);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(p[j][i] == -1) continue;
            p[j][i+1] = p[p[j][i]][i];
            dist[j][i+1] = dist[j][i] + dist[p[j][i]][i];
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;

        int diff = depth[a] - depth[b];
        if(diff < 0) swap(a, b), diff *= (-1);

        int cnt = 0;
        for(int j = 0; diff; j++)
        {
            if(diff&1) cnt += dist[a][j], a = p[a][j];
            diff >>= 1;
        }

        if(a != b)
        {
            for(int j = 19; j >= 0; j--)
            {
                if(p[a][j] != -1 && p[b][j] != -1 && p[a][j] != p[b][j])
                {
                    cnt += (dist[a][j] + dist[b][j]);
                    a = p[a][j];
                    b = p[b][j];
                }
            }

            cnt += (dist[a][0] + dist[b][0]);
            a = p[a][0];
        }

        cout << cnt << '\n';
    }

    return 0;
}
