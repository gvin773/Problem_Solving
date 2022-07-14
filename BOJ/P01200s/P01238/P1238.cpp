#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, x, a, b, t, dist[1000], ret[1000], ans;
vector<pii> edge[2][1000];

int main()
{
    onlycc;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        edge[0][a-1].push_back({b-1,t});
        edge[1][b-1].push_back({a-1,t});
    }

    for(int tc = 0; tc < 2; tc++)
    {
        bool visited[1000] = {};
        priority_queue<pii, vector<pii>, greater<pii>> H;
        for(int i = 0; i < n; i++) dist[i] = 987654321;
        dist[--x] = 0;

        H.push({0, x});
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
            for(auto &p : edge[tc][cur])
            {
                int next = p.first, d = p.second;
                if(dist[next] > dist[cur] + d)
                {
                    dist[next] = dist[cur] + d;
                    H.push({dist[next], next});
                }
            }
        }
        x++;

        for(int i = 0; i < n; i++) ret[i] += dist[i];
    }
    for(int i = 0; i < n; i++) ans = max(ans, ret[i]);
    cout << ans;

    return 0;
}
