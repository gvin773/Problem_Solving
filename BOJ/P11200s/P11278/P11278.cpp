#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, na, nb, clk[30000], clkcnt, sccn[30000], SN, ret[30000];
vector<int> edge[30000];
stack<int> S;
bool finished[30000];
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

        a = (a < 0 ? -(a+1)*2 : a*2-1);
        b = (b < 0 ? -(b+1)*2 : b*2-1);
        edge[a%2 ? a-1 : a+1].push_back(b);
        edge[b%2 ? b-1 : b+1].push_back(a);
    }

    for(int i = 0; i < 2*V; i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < V; i++)
    {
        if(sccn[i*2] == sccn[i*2+1])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1 << '\n';

    memset(ret, -1, sizeof(ret));
    pii P[30000];
    for(int i = 0; i < 2*V; i++) P[i] = {sccn[i], i};
    sort(P, P+2*V);

    for(int i = 2*V-1; i >= 0; i--)
    {
        int now = P[i].second;
        if(ret[now/2] == -1) ret[now/2] = !(now&1);
    }

    for(int i = 0; i < V; i++) cout << ret[i] << ' ';

    return 0;
}
