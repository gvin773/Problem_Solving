#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, t[500], pre, indegree[5000], ret[500];
vector<ll> edge[500], ans;
queue<ll> q;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        while(1)
        {
            cin >> pre;
            if(pre == -1) break;
            indegree[i]++;
            edge[pre-1].push_back(i);
        }
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
        ret[x] += t[x];
        for(auto next : edge[x]) ret[next] = max(ret[next], ret[x]);
    }

    for(int i = 0; i < n; i++) cout << ret[i] << '\n';

    return 0;
}
