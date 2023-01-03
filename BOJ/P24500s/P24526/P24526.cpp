#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 100000;

int V, E, a, b, clk[SIZE], clkcnt, sccn[SIZE], SN, ans;
vector<int> edge[SIZE];
stack<int> S;
bool finished[SIZE], visited[SIZE];
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

void mark(int now)
{
    visited[now] = true;
    for(auto x : edge[now]) if(!visited[x]) mark(x);
}

int main()
{
    onlycc;
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b;
        edge[b-1].push_back(a-1);
    }
    for(int i = 0; i < V; i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && SCC[sccn[i]].size() > 1) mark(i);
    }
    for(int i = 0; i < V; i++) if(!visited[i]) ans++;
    cout << ans;

    return 0;
}
