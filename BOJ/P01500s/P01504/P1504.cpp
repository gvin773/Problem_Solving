#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int N, E, K, a, b, c, v1, v2, dist[1000];
vector<pii> edge[200000];

int get_dist(int s, int e)
{
    for(int i = 0; i < N; i++) dist[i] = 987654321;
    dist[--s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> H;
    bool visited[1000] = {};

    H.push({dist[s], s});
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

    return (dist[e-1] == 987654321 ? -1 : dist[e-1]);
}

int check(int a, int b, int c)
{
    if(a < 0 || b < 0 || c < 0) return -1;
    else return a+b+c;
}

int main()
{
    onlycc;
    cin >> N >> E;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        edge[a-1].push_back({b-1,c});
        edge[b-1].push_back({a-1,c});
    }
    cin >> v1 >> v2;

    int d1 = check(get_dist(1, v1), get_dist(v1, v2), get_dist(v2, N));
    int d2 = check(get_dist(1, v2), get_dist(v2, v1), get_dist(v1, N));
    if(d1 < 0 && d2 < 0) cout << -1;
    else if(d1 < 0) cout << d2;
    else if(d2 < 0) cout << d1;
    else cout << min(d1, d2);

    return 0;
}
