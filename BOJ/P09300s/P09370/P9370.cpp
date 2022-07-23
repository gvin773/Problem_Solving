#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, m, s, g, h, a, b, d, t, sx[2222], gx[2222], hx[2222], cand[111];

ll dijkstra(int S, int E, const vector<pll> (&edge)[2222], int save)
{
    bool visited[2222] = {};
    ll dist[2222] = {};
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

    if(save == 1) for(int i = 0; i < n; i++) sx[i] = dist[i];
    if(save == 2) for(int i = 0; i < n; i++) gx[i] = dist[i];
    if(save == 3) for(int i = 0; i < n; i++) hx[i] = dist[i];
    return dist[E];
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        vector<pll> edge[2222];
        cin >> n >> m >> t >> s >> g >> h;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            edge[a-1].push_back({b-1, d});
            edge[b-1].push_back({a-1, d});
        }
        for(int i = 0; i < t; i++) cin >> cand[i];

        dijkstra(s-1, g-1, edge, 1);
        dijkstra(g-1, h-1, edge, 2);
        dijkstra(h-1, g-1, edge, 3);

        bool visited[2222] = {};
        for(int i = 0; i < t; i++) if(sx[cand[i]-1] == sx[g-1] + gx[h-1] + hx[cand[i]-1]) visited[cand[i]-1] = true;
        for(int i = 0; i < t; i++) if(sx[cand[i]-1] == sx[h-1] + hx[g-1] + gx[cand[i]-1]) visited[cand[i]-1] = true;

        vector<ll> ans;
        for(int i = 0; i < n; i++) if(visited[i]) ans.push_back(i+1);

        sort(ans.begin(), ans.end());
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
