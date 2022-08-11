#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, m, clk[1500], clkcnt, sccn[1500], SN, cnt, indegree[1500], Rank[1500];
string a, b;
vector<int> edge[1500], sedge[1500], ts;
stack<int> S;
bool finished[1500];
vector<vector<int>> SCC;
unordered_map<string, int> si;
queue<int> q;

ll dfs(int now)
{
    clk[now] = ++clkcnt;
    S.push(now);

    ll ret = clk[now];
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
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> b >> m;
        if(si.find(b) == si.end()) si[b] = cnt++;
        for(int j = 0; j < m; j++)
        {
            cin >> a;
            if(si.find(a) == si.end()) si[a] = cnt++;
            edge[si[a]].push_back(si[b]);
        }
    }
    for(int i = 0; i < cnt; i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < cnt; i++)
    {
        for(auto to : edge[i])
        {
            if(sccn[i] != sccn[to])
            {
                sedge[sccn[i]].push_back(sccn[to]);
                indegree[sccn[to]]++;
            }
        }
    }

    for(int i = 0; i < SN; i++) if(!indegree[i]) q.push(i);
    while(!q.empty())
    {
        ll now = q.front();
        q.pop();
        ts.push_back(now);

        for(auto x : sedge[now]) if(--indegree[x] == 0) q.push(x);
    }

    for(int i = 0; i < 1500; i++) Rank[i] = 1;
    for(auto x : ts)
    {
        for(auto now : SCC[x])
        {
            for(auto next : edge[now])
            {
                if(sccn[now] != sccn[next])
                {
                    Rank[next] += Rank[now];
                }
            }
        }
    }

    cin >> a;
    cout << Rank[si[a]];

    return 0;
}
