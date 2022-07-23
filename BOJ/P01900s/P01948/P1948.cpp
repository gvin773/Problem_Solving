#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, a, b, c, indegree[10000], s, e, t[10000], cnt;
vector<pll> edge[10000], redge[10000];
queue<ll> q;
bool visited[10000];

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        indegree[b-1]++;
        edge[a-1].push_back({b-1, c});
        redge[b-1].push_back({a-1, c});
    }
    cin >> s >> e;

    for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i);
    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            cout << 0;
            return 0;
        }

        ll now = q.front();
        q.pop();

        for(auto x : edge[now])
        {
            t[x.first] = max(t[x.first], t[now] + x.second);
            if(--indegree[x.first] == 0) q.push(x.first);
        }
    }
    cout << t[e-1] << '\n';

    q.push(e-1);
    visited[e-1] = true;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            q.pop();

            for(auto x : redge[now])
            {
                if(t[now] == t[x.first] + x.second)
                {
                    cnt++;
                    if(!visited[x.first])
                    {
                        visited[x.first] = true;
                        q.push(x.first);
                    }
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
