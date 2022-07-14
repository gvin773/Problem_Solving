#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, s, d, u, v, p, dist[600], Prev[600];

ll dijkstra(int S, int E, const vector<pll> (&edge)[600], vector<ll> (&Prev)[600])
{
    bool visited[600] = {};
    priority_queue<pll, vector<pll>, greater<pll>> H;

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
            ll next = p.first, d = p.second;
            if(dist[next] == dist[cur] + d) Prev[next].push_back(cur);
            if(dist[next] > dist[cur] + d)
            {
                dist[next] = dist[cur] + d;
                H.push({dist[next], next});
                while(!Prev[next].empty()) Prev[next].pop_back();
                Prev[next].push_back(cur);
            }
        }
    }

    return dist[E];
}

int main()
{
    onlycc;
    while(1)
    {
        vector<pll> edge[600];
        vector<ll> Prev[600];
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> s >> d;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> p;
            edge[u].push_back({v, p});
        }
        dijkstra(s, 0, edge, Prev);

        queue<int> q;
        q.push(d);
        bool visited[600] = {};

        while(!q.empty())
        {
            int Size = q.size();
            for(int i = 0; i < Size; i++)
            {
                int now = q.front();
                q.pop();
                if(visited[now]) continue;
                visited[now] = true;
                for(auto j : Prev[now])
                {
                    q.push(j);
                    for(auto x = edge[j].begin(); x != edge[j].end(); x++)
                    {
                        if(x->first == now)
                        {
                            edge[j].erase(x);
                            break;
                        }
                    }
                }
            }
        }

        ll ans = dijkstra(s, d, edge, Prev);
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }

    return 0;
}
