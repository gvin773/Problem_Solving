#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, k, d[1000], a, b, indegree[1000], ret[1000], w;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        vector<ll> edge[1000], ans;
        queue<ll> q;
        memset(indegree, 0, sizeof(indegree));
        memset(ret, 0, sizeof(ret));
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> d[i];
        for(int i = 0; i < k; i++)
        {
            cin >> a >> b;
            indegree[b-1]++;
            edge[a-1].push_back(b-1);
        }

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
            ans.push_back(now);

            for(auto x : edge[now]) if(--indegree[x] == 0) q.push(x);
        }

        for(auto x : ans)
        {
            ret[x] += d[x];
            for(auto next : edge[x]) ret[next] = max(ret[next], ret[x]);
        }

        cin >> w;
        cout << ret[w-1] << '\n';
    }

    return 0;
}
