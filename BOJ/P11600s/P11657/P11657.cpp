#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll n, m, a, b, c, dist[555];
vector<pll> edge[555];
bool cycle;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a-1].push_back({b-1, c});
    }

    fill(dist+1, dist+n, LLONG_MAX);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(auto &p: edge[j])
            {
                if(dist[j] != LLONG_MAX && dist[p.first] > dist[j] + p.second)
                {
                    dist[p.first] = dist[j] + p.second;
                    if(i == n-1) cycle = true;
                }
            }
        }
    }

    if(cycle) cout << -1;
    else for(int i = 1; i < n; i++) cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << '\n';

    return 0;
}
