#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, m, t[501], r[501], indegree[501], a, b;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        bool flag[501][501] = {};
        memset(indegree, 0, sizeof(indegree));
        vector<ll> edge[501], ans;
        queue<ll> q;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> t[i];
            r[t[i]] = i;
        }

        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            if(r[b] < r[a]) swap(a, b);

            indegree[a]++;
            edge[b].push_back(a);
            flag[a][b] = true;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j) continue;
                if(r[i] < r[j] && !flag[i][j])
                {
                    indegree[j]++;
                    edge[i].push_back(j);
                }
            }
        }

        for(int i = 1; i <= n; i++) if(!indegree[i]) q.push(i);
        for(int i = 1; i <= n; i++)
        {
            if(q.empty())
            {
                cout << "IMPOSSIBLE\n";
                goto xy;
            }

            ll now = q.front();
            q.pop();
            ans.push_back(q.size() >= 2 ? -999 : now);

            for(int x : edge[now]) if(--indegree[x] == 0) q.push(x);
        }

        for(auto x : ans)
        {
            if(x == -999) cout << "? ";
            else cout << x << ' ';
        }
        cout << '\n';
        xy:;
    }

    return 0;
}
