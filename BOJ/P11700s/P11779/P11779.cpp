#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, m, s, e, a, b, c, dist[1000], before[1000];
vector<pii> edge[1000];
priority_queue<pii, vector<pii>, greater<pii>> H;
bool visited[1000];

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a-1].push_back({b-1,c});
    }
    cin >> s >> e;

    for(int i = 0; i < n; i++) before[i] = -1;
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
                before[next] = cur;
                H.push({dist[next], next});
            }
        }
    }

    int now = e-1;
    vector<int> v;
    while(before[now] != -1)
    {
        v.push_back(now);
        now = before[now];
    }
    cout << dist[e-1] << '\n' << v.size()+1 << '\n' << s+1 << ' ';
    for(int i = v.size()-1; i >= 0; i--) cout << v[i]+1 << ' ';

    return 0;
}
