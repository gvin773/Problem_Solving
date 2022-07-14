#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, a, b, c, Prev[1111];
vector<pll> edge[1111], ans;
bool used[1111][1111];

ll dijkstra(int S, int E)
{
    bool visited[1111] = {};
    ll dist[1111] = {};
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
            if(dist[next] > dist[cur] + d)
            {
                dist[next] = dist[cur] + d;
                H.push({dist[next], next});
                Prev[next] = cur;
            }
        }
    }

    return dist[E];
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a-1].push_back({b-1, c});
        edge[b-1].push_back({a-1, c});
    }
    dijkstra(0, n-1);
    for(int i = 0; i < n; i++)
    {
        if(!used[i][Prev[i]])
        {
            used[i][Prev[i]] = true;
            if(i != 0) ans.push_back({i, Prev[i]});
        }
    }
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x.first+1 << ' ' << x.second+1 << '\n';

    return 0;
}
