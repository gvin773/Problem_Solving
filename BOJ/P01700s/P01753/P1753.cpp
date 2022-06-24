#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int V, E, K, u, v, w, dist[20000];
vector<pair<int,int>> edge[300000];
bool visited[20000];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> H;

int main()
{
    onlycc;
    cin >> V >> E >> K;
    for(int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edge[u-1].push_back({v-1,w});
    }

    for(int i = 0; i < V; i++) dist[i] = 987654321;
    dist[--K] = 0;

    H.push({0, K});
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

    for(int i = 0; i < V; i++)
    {
        if(dist[i] == 987654321) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
