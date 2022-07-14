#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, dist[150][150], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string a[150];

ll dijkstra(pii S, pii E)
{
    bool visited[150][150] = {};
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> H;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) dist[i][j] = LLONG_MAX;
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
            if(!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;

            int d = a[nx][ny] - '0';
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
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << dijkstra({0,0}, {n-1,m-1}) + (a[0][0]-'0');

    return 0;
}
