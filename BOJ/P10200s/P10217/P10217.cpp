#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, m, k, u, v, c, D, dist[100][10001], ans;

int dijkstra(int S, int E, vector<pair<int, pii>> (&edge)[100])
{
    bool visited[100][10001] = {};
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> H;

    for(int i = 0; i < n; i++) for(int j = 0; j <= m; j++) dist[i][j] = 1000000000;
    dist[S][m] = 0;

    H.push({0, {S, m}});
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
            int next = p.first, d = p.second.second, cost = p.second.first;
            if(left >= cost && dist[next][left-cost] > dist[cur][left] + d)
            {
                dist[next][left-cost] = dist[cur][left] + d;
                H.push({dist[next][left-cost], {next, left - cost}});
            }
        }
    }

    int ret = 1000000000;
    for(int i = 0; i <= m; i++) ret = min(ret, dist[E][i]);
    return ret;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        vector<pair<int, pii>> edge[100];
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> u >> v >> c >> D;
            edge[u-1].push_back({v-1, {c, D}});
        }

        ans = dijkstra(0, n-1, edge);
        if(ans == 1000000000) cout << "Poor KCM\n";
        else cout << ans << '\n';
    }

    return 0;
}
