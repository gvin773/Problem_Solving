#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, m, a, b, c, dist[1111];
bool visited[1111];

void dfs(int now, const vector<pll> (&edge)[1111], unordered_set<ll> &S)
{
    visited[now] = true;
    for(auto x : edge[now]) if(!visited[now] && S.find(x.first) != S.end()) dfs(x.first, edge, S);
}

int main()
{
    onlycc;
    cin >> tc;
    for(int z = 1; z <= tc; z++)
    {
        vector<pll> edge[1111];
        vector<ll> redge[1111];
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
            redge[b].push_back(a);
        }

        dist[0] = 0;
        fill(dist+1, dist+n, LLONG_MAX);
        queue<ll> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(auto &p: edge[j])
                {
                    ll next = p.first, d = p.second;
                    if(dist[j] != LLONG_MAX && dist[next] > dist[j] + d)
                    {
                        dist[next] = dist[j] + d;
                        if(i == n-1) q.push(j);
                    }
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        while(!q.empty())
        {
            int Size = q.size();
            for(int s = 0; s < Size; s++)
            {
                int now = q.front();
                q.pop();

                if(now == 0) break;

                for(auto x : edge[now])
                {
                    if(!visited[x.first])
                    {
                        visited[x.first] = true;
                        q.push(x.first);
                    }
                }
            }
        }

        cout << "Case #" << z << ": ";
        if(!visited[0] && !(dist[0] < 0)) cout << "not ";
        cout << "possible\n";
    }

    return 0;
}
