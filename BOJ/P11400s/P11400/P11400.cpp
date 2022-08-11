#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[100000], clkcnt;
vector<int> edge[100000];
stack<pii> S;
vector<vector<pii>> BCC;
set<pii> ans;

ll dfs(int now, int prev = -1)
{
    clk[now] = ++clkcnt;

    int ret = clk[now];
    for(auto next : edge[now])
    {
        if(prev == next) continue;
        if(clk[now] > clk[next]) S.push({now, next});
        if(clk[next] > 0) ret = min(ret, clk[next]);
        else
        {
            int temp = dfs(next, now);
            ret = min(ret, temp);
            if(temp >= clk[now])
            {
                if(temp > clk[now]) ans.insert({min(now, next), max(now, next)});
                vector<pii> v;
                while(!S.empty() && S.top() != make_pair(now, next))
                {
                    v.push_back(S.top());
                    S.pop();
                }
                v.push_back(S.top());
                S.pop();

                BCC.push_back(v);
            }
        }
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> V >> E;
    while(E--)
    {
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    for(int i = 0; i < V; i++) if(!clk[i]) dfs(i);

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x.first+1 << ' ' << x.second+1 << '\n';

    return 0;
}
