#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll tc, n, m, w, s, e, t, dist[501];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        bool cycle = false, visited[501] = {};
        vector<pii> edge[501];
        cin >> n >> m >> w;
        for(int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            edge[s-1].push_back({e-1,t});
            edge[e-1].push_back({s-1,t});
        }
        for(int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            edge[s-1].push_back({e-1,-t});
        }

        for(int now = 0; now < n; now++)
        {
            if(!visited[now])
            {
                fill(dist, dist+n, 987654321);
                dist[now] = 0;
                for(int i = 0; i< n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        for(auto &p: edge[j])
                        {
                            int next = p.first, d = p.second;
                            if(dist[j] != 987654321 && dist[next] > dist[j] + d)
                            {
                                dist[next] = dist[j] + d;
                                if(i == n-1) cycle = true;
                            }
                        }
                    }
                }
                for(int i = 0; i < n; i++) if(dist[i] != 987654321) visited[i] = true;
                if(cycle) goto xy;
            }
        }
        xy: cout << (cycle ? "YES\n" : "NO\n");
    }

    return 0;
}
