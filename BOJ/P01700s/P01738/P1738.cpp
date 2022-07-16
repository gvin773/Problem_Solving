#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, a, b, c, dist[111], Prev[111];
vector<pll> edge[111];
vector<ll> redge[111], ans;
bool visited[111];

void dfs(int now)
{
    visited[now] = true;
    for(auto x : redge[now]) if(!visited[x]) dfs(x);
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a-1].push_back({b-1, -c});
        redge[b-1].push_back(a-1);
    }
    dfs(n-1);

    fill(dist+1, dist+n, LLONG_MAX);
    fill(Prev, Prev+n, -1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(auto &p: edge[j])
            {
                ll next = p.first, d = p.second;
                if(dist[j] != LLONG_MAX && dist[next] > dist[j] + d)
                {
                    dist[next] = dist[j] + d;
                    Prev[next] = j;
                    if(i == n-1 && visited[next])
                    {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }

    if(dist[n-1] == LLONG_MAX)
    {
        cout << -1;
        return 0;
    }

    ll now = n-1;
    while(now != 0)
    {
        ans.push_back(now);
        now = Prev[now];
    }
    cout << 1 << ' ';
    for(auto x = ans.rbegin(); x != ans.rend(); x++) cout << *x+1 << ' ';

    return 0;
}
