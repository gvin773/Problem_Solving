#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, V, E, a, b, clk[100000], clkcnt, sccn[100000], SN;
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
    cin >> tc;
    while(tc--)
    {
        cin >> V >> E;
        for(int i = 0; i < V; i++) edge[i].clear();
        for(int i = 0; i < E; i++)
        {
            cin >> a >> b;
            edge[a].push_back(b);
        }

        SCC.clear();
        memset(finished, 0, sizeof(finished));
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        memset(sccn, 0, sizeof(sccn));
        SN = 0;
        for(int i = 0; i < V; i++) if(!clk[i]) dfs(i);

        int deg[100000] = {};
        for(int i = 0; i < V; i++) for(auto to : edge[i]) if(sccn[i] != sccn[to]) deg[sccn[to]]++;

        int cnt = 0;
        for(int i = 0; i < SN; i++) if(!deg[i]) cnt++;
        if(cnt != 1)
        {
            cout << "Confused\n\n";
            continue;
        }

        vector<int> ans;
        for(int i = 0; i < SN; i++) if(!deg[i]) for(auto x : SCC[i]) ans.push_back(x);

        sort(ans.begin(), ans.end());
        for(auto x : ans) cout << x << '\n';
        cout << '\n';
    }

    return 0;
}
