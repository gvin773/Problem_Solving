#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[500000], clkcnt, sccn[500000], SN, money[500000], start, p, smoney[500000], indegree[500000], Mmoney[500000], MAX;
vector<int> edge[500000], sedge[500000], ans;
stack<int> S;
bool finished[500000], rest[500000], srest[500000], possible[500000];
vector<vector<int>> SCC;
queue<int> q;

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

    for(int i = 0; i < V; i++) cin >> money[i];
    cin >> start >> p;
    start--;
    for(int i = 0; i < p; i++)
    {
        cin >> a;
        rest[a-1] = true;
    }

    for(int i = 0; i < V; i++)
    {
        if(rest[i]) srest[sccn[i]] = true;
        smoney[sccn[i]] += money[i];
        for(auto to : edge[i])
        {
            if(sccn[i] != sccn[to])
            {
                sedge[sccn[i]].push_back(sccn[to]);
                indegree[sccn[to]]++;
            }
        }
    }

    start = sccn[start];
    possible[start] = true;
    for(int i = 0; i < SN; i++) Mmoney[i] = smoney[i];
    for(int i = 0; i < SN; i++) if(!indegree[i]) q.push(i);
    while(!q.empty())
    {
        ll now = q.front();
        q.pop();
        ans.push_back(now);

        for(auto x : sedge[now])
        {
            if(possible[now])
            {
                Mmoney[x] = max(Mmoney[x], Mmoney[now]+smoney[x]);
                possible[x] = true;
            }
            if(--indegree[x] == 0) q.push(x);
        }
    }

    MAX = Mmoney[start];
    for(int i = 0; i < SN; i++) if(possible[i] && srest[i]) MAX = max(MAX, Mmoney[i]);
    cout << MAX;

    return 0;
}
