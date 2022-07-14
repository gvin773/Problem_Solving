#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, r, item[100], a, b, l, dist[100], ret, ans;
vector<pii> edge[100];

int main()
{
    onlycc;
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) cin >> item[i];
    for(int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        edge[a-1].push_back({b-1,l});
        edge[b-1].push_back({a-1,l});
    }

    for(int s = 1; s <= n; s+=2)
    {
        bool visited[100] = {};
        priority_queue<pii, vector<pii>, greater<pii>> H;
        for(int i = 0; i < n; i++) dist[i] = 987654321;
        dist[--s] = 0;

        H.push({0, s});
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

        ret = 0;
        for(int i = 0; i < n; i++) if(dist[i] <= m) ret += item[i];
        ans = max(ans, ret);
    }
    cout << ans;

    return 0;
}
