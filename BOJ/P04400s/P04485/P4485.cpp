#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, a[150][150], dist[150][150], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

ll dijkstra(pii S, pii E)
{
    bool visited[150][150] = {};
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> H;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = LLONG_MAX;
    dist[S.first][S.second] = 0;

    H.push({0, S});
    while(!H.empty())
    {
        pii cur;
        do
        {
            cur = H.top().second;
            H.pop();
        }while(!H.empty() && visited[cur.first][cur.second]);
        if(visited[cur.first][cur.second]) break;

        visited[cur.first][cur.second] = true;
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first+dx[i], ny = cur.second+dy[i];
            if(!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;

            int d = a[nx][ny];
            if(dist[nx][ny] > dist[cur.first][cur.second] + d)
            {
                dist[nx][ny] = dist[cur.first][cur.second] + d;
                H.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    return dist[E.first][E.second];
}

int main()
{
    onlycc;
    for(int idx = 1; ; idx++)
    {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
        cout << "Problem " << idx << ": " << dijkstra({0,0}, {n-1,n-1}) + a[0][0] << '\n';
    }

    return 0;
}
