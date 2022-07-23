#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[10000], clkcnt, sccn[10000], SN;
vector<int> edge[10000];
stack<int> S;
bool finished[10000];
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
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b;
        edge[a-1].push_back(b-1);
    }

    for(int i = 0; i < V; i++) if(!clk[i]) dfs(i);

    sort(SCC.begin(), SCC.end());
    cout << SN << '\n';
    for(auto now : SCC)
    {
        for(auto x : now) cout << x+1 << ' ';
        cout << -1 << '\n';
    }

    return 0;
}
