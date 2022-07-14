#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, f, s, t, u, v, w, dist[50000], ans;
vector<pii> edge[50000];


ll dijkstra(int S, int E)
{
    bool visited[50000] = {};
    priority_queue<pii, vector<pii>, greater<pii>> H;

    for(int i = 0; i < n; i++) dist[i] = LLONG_MAX;
    dist[S] = 0;

    H.push({0, S});
    while(!H.empty())
    {
        int cur;
        do
        {
            cur = H.top().second;
            H.pop();
        }while(!H.empty() && visited[cur]);
        if(visited[cur]) break;

        visited[cur] = true;
        for(auto &p : edge[cur])
        {
            int next = p.first, d = p.second;
            if(dist[next] > dist[cur] + d)
            {
                dist[next] = dist[cur] + d;
                H.push({dist[next], next});
            }
        }
    }

    return dist[E];
}

int main()
{
    onlycc;
    cin >> n >> m >> f >> s >> t;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }

    ans = dijkstra(s, t);
    for(int i = 0; i < f; i++)
    {
        cin >> u >> v;

        ll t1 = dijkstra(s, u), t2 = dijkstra(v, t);
        if(t1 != LLONG_MAX && t2 != LLONG_MAX) ans = min(ans, t1+t2);
    }
    cout << ans;

    return 0;
}
