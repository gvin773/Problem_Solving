#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, s, e, m, a, b, c, money[55], dist[55];
vector<pll> edge[55];
bool visited[55];

int main()
{
    onlycc;
    cin >> n >> s >> e >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    for(int i = 0; i < n; i++) cin >> money[i];

    fill(dist, dist+n, LLONG_MAX);
    dist[s] = -money[s];
    queue<ll> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(auto &p: edge[j])
            {
                ll next = p.first, d = p.second;
                if(dist[j] != LLONG_MAX && dist[next] > dist[j] + d - money[next])
                {
                    dist[next] = dist[j] + d - money[next];
                    if(i == n-1) q.push(j);
                }
            }
        }
    }
    if(dist[e] == LLONG_MAX)
    {
        cout << "gg";
        return 0;
    }

    memset(visited, 0, sizeof(visited));
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            int now = q.front();
            q.pop();

            for(auto x : edge[now])
            {
                if(!visited[x.first])
                {
                    visited[x.first] = true;
                    q.push(x.first);
                }
            }
        }
    }

    if(visited[e]) cout << "Gee";
    else cout << -dist[e];

    return 0;
}
