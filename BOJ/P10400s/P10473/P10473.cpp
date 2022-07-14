#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld X[111], Y[111];
ll n;
vector<pid> edge[111];

ld dijkstra(int S, int E)
{
    bool visited[111] = {};
    ld dist[111] = {};
    priority_queue<pid, vector<pid>, greater<pid>> H;

    for(int i = 0; i < n+2; i++) dist[i] = 1e10;
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
            int next = p.first;
            ld d = p.second;
            if(dist[next] > dist[cur] + d)
            {
                dist[next] = dist[cur] + d;
                H.push({dist[next], next});
            }
        }
    }

    return dist[E];
}

ld D(ld a, ld b, ld c, ld d)
{
    return sqrt((c-a)*(c-a) + (d-b)*(d-b));
}

int main()
{
    onlycc;
    cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> n;
    for(int i = 2; i < n+2; i++) cin >> X[i] >> Y[i];

    for(int i = 0; i < n+2; i++)
    {
        if(i == 1) continue;
        for(int j = 0; j < n+2; j++)
        {
            if(i == j) continue;
            if(i == 0) edge[i].push_back({j, D(X[i], Y[i], X[j], Y[j]) / (double)5});
            else edge[i].push_back({j, 2 + abs(D(X[i], Y[i], X[j], Y[j]) - 50) / (double)5});
        }
    }


    ld ans = dijkstra(0, 1);
    for(int i = 2; i < n+2; i++) ans = min(ans, dijkstra(0, i) + dijkstra(i, 1));
    cout.precision(10);
    cout << fixed << ans;

    return 0;
}
