#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[100000], clkcnt, sccn[100000], SN, deg[100000], ans;
vector<int> edge[100000];
stack<int> S;
bool finished[100000];
vector<vector<int>> SCC;

int dfs(int now)
{
    clk[now] = ++clkcnt;
    S.push(now);

    int ret = clk[now];
    for(auto next : edge[now])
    {
        if(!clk[next]) ret = min(ret, dfs(next));
        else if(!finished[next]) ret = min(ret, clk[next]);
    }

    if(ret == clk[now])
    {
        vector<int> v;
        while(1)
        {
            int x = S.top();
            S.pop();
            v.push_back(x);
            sccn[x] = SN;
            finished[x] = true;

            if(now == x) break;
        }
        SN++;

        sort(v.begin(), v.end());
        SCC.push_back(v);
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> V >> E;
    for(int i = 0; i < V; i++) edge[i].clear();
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b;
        edge[a-1].push_back(b-1);
    }
    for(int i = 0; i < V; i++) if(!clk[i]) dfs(i);
    for(int i = 0; i < V; i++) for(auto to : edge[i]) if(sccn[i] != sccn[to]) deg[sccn[to]]++;
    for(int i = 0; i < SN; i++) if(!deg[i]) ans++;
    cout << ans;

    return 0;
}
