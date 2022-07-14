#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, d, e, h[100000], a, b, c, ans = LLONG_MIN;
vector<pll> up[100000], down[100000];

vector<ll> dijkstra(int S, int E, const vector<pll> (&edge)[100000])
{
    bool visited[100000] = {};
    vector<ll> dist(100000);
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
            }
        }
    }

    return dist;
}

int main()
{
    onlycc;
    cin >> n >> m >> d >> e;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if(h[a-1] > h[b-1])
        {
            up[b-1].push_back({a-1, c});
            down[a-1].push_back({b-1, c});
        }
        else if(h[a-1] < h[b-1])
        {
            up[a-1].push_back({b-1, c});
            down[b-1].push_back({a-1, c});
        }
    }

    vector<ll> froms = dijkstra(0, n-1, up), frome = dijkstra(n-1, 0, up);
    for(int goal = 1; goal < n-1; goal++)
    {
        if(froms[goal] == LLONG_MAX || frome[goal] == LLONG_MAX) continue;
        ans = max(ans, h[goal]*e - (froms[goal] + frome[goal])*d);
    }
    if(ans == LLONG_MIN) cout << "Impossible";
    else cout << ans;

    return 0;
}
