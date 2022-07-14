#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll N, energy[100001], a, b, c, p[100001], Next[100001][18], dist[100001][18];
vector<pll> d[100001];

void dfs(int now)
{
    for(auto x : d[now])
    {
        ll n = x.first, cost = x.second;
        if(p[now] == n) continue;
        p[n] = now;

        Next[n][0] = now, dist[n][0] = cost;
        for(int i = 1; i < 18; i++)
        {
            if(Next[Next[n][i-1]][i-1] == -1) break;
            Next[n][i] = Next[Next[n][i-1]][i-1];
            dist[n][i] = dist[n][i-1] + dist[Next[n][i-1]][i-1];
        }

        dfs(n);
    }
}

int main()
{
    onlycc;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> energy[i];
    for(int i = 1; i < N; i++)
    {
        cin >> a >> b >> c;
        d[a].push_back({b, c});
        d[b].push_back({a, c});
    }
    memset(Next, -1, sizeof(Next));
    memset(dist, -1, sizeof(dist));
    dfs(1);

    for(int i = 1; i <= N; i++)
    {
        if(i == 1)
        {
            cout << 1 << '\n';
            continue;
        }

        int now = i;
        for(ll j = 17; j >= 0; j--)
        {
            if(Next[now][j] == -1) continue;
            if(dist[now][j] <= energy[i])
            {
                energy[i] -= dist[now][j];
                now = Next[now][j];
            }
        }
        cout << now << '\n';
    }

    return 0;
}
