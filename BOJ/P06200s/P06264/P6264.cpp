#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, clk[1500], clkcnt, sccn[1500], SN, cnt, indegree[1500];
string a, b;
vector<int> edge[1500], sedge[1500], ts;
stack<int> S;
bool finished[1500];
vector<vector<int>> SCC;
unordered_map<string, int> si;
unordered_map<int, string> is;
queue<int> q;
unordered_set<int> ans;

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
    while(1)
    {
        cin >> n;
        cin.ignore(256, '\n');
        if(n == 0) break;
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        memset(sccn, 0, sizeof(sccn));
        SN = 0;
        cnt = 0;
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i < 1500; i++) edge[i].clear();
        for(int i = 0; i < 1500; i++) sedge[i].clear();
        ts.clear();
        while(!S.empty()) S.pop();
        memset(finished, 0, sizeof(finished));
        SCC.clear();
        si.clear();
        is.clear();
        while(!q.empty()) q.pop();
        ans.clear();
        for(int i = 0; i < n; i++)
        {
            getline(cin, a);

            istringstream ss(a);
            getline(ss, b, ' ');
            if(si.find(b) == si.end())
            {
                is[cnt] = b;
                si[b] = cnt++;
            }
            while(getline(ss, a, ' '))
            {
                if(si.find(a) == si.end())
                {
                    is[cnt] = a;
                    si[a] = cnt++;
                }
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

        for(int i = 0; i < SN; i++)
        {
            if(!indegree[i])
            {
                q.push(i);
                for(auto x : SCC[i]) ans.insert(x);
            }
        }
        while(!q.empty())
        {
            ll now = q.front();
            q.pop();
            ts.push_back(now);

            for(auto x : sedge[now]) if(--indegree[x] == 0) q.push(x);
        }

        bool checker[1500] = {};
        for(auto iter = ts.rbegin(); iter != ts.rend(); iter++)
        {
            if(SCC[*iter].size() > 1)
            {
                checker[*iter] = true;
                continue;
            }
            for(auto next : sedge[*iter])
            {
                if(checker[next])
                {
                    checker[*iter] = true;
                    break;
                }
            }
        }
        for(auto x : ts) if(checker[x]) for(auto now : SCC[x]) ans.insert(now);

        vector<string> sans;
        for(auto x : ans) sans.push_back(is[x]);

        sort(sans.begin(), sans.end());
        cout << sans.size() << '\n';
        for(auto x : sans) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
