#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, a, b, indegree[32000];
vector<ll> edge[32000], ans;
queue<ll> q;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
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
        ans.push_back(now+1);

        for(auto x : edge[now]) if(--indegree[x] == 0) q.push(x);
    }

    for(auto x : ans) cout << x << ' ';

    return 0;
}
