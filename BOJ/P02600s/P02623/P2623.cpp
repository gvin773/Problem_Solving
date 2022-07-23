#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, num, pre, now, indegree[1000];
vector<ll> edge[1000], ans;
queue<ll> q;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> num;
        if(!num) continue;

        cin >> pre;
        for(int j = 1; j < num; j++)
        {
            cin >> now;
            indegree[now-1]++;
            edge[pre-1].push_back(now-1);
            pre = now;
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

        now = q.front();
        q.pop();
        ans.push_back(now+1);

        for(auto x : edge[now]) if(--indegree[x] == 0) q.push(x);
    }

    for(auto x : ans) cout << x << '\n';

    return 0;
}
