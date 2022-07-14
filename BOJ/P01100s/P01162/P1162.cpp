#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, k, a, b, c, dist[10000][21], ans = LLONG_MAX;
vector<pll> edge[10000];
vector<ll> ret;

void dijkstra(int S, int E)
{
    bool visited[10000][21] = {};
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> H;

    for(int i = 0; i < n; i++) for(int j = 0; j <= k; j++) dist[i][j] = LLONG_MAX;
    dist[S][k] = 0;

    H.push({0, {S, k}});
    while(!H.empty())
    {
        int cur, left;
        do
        {
            cur = H.top().second.first;
            left = H.top().second.second;
            H.pop();
        }while(!H.empty() && visited[cur][left]);
        if(visited[cur][left]) break;

        visited[cur][left] = true;
        for(auto &p : edge[cur])
        {
            ll next = p.first, d = p.second;
            if(dist[next][left] > dist[cur][left] + d)
            {
                dist[next][left] = dist[cur][left] + d;
                H.push({dist[next][left], {next, left}});
            }
            if(left > 0 && dist[next][left-1] > dist[cur][left])
            {
                dist[next][left-1] = dist[cur][left];
                H.push({dist[next][left-1], {next, left-1}});
            }
        }
    }

    //return dist[E];
}

int main()
{
    onlycc;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a-1].push_back({b-1, c});
        edge[b-1].push_back({a-1, c});
    }

    dijkstra(0, n-1);
    for(int i = 0; i <= k; i++) ans = min(ans, dist[n-1][i]);
    cout << ans;

    return 0;
}
