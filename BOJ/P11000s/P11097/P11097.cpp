#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, clk[500], clkcnt, sccn[500], SN;
vector<int> edge[500];
stack<int> S;
bool finished[500], sedge[500][500];
vector<vector<int>> SCC;
string adj[500];
vector<pii> ans;

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
        cin >> n;
        for(int i = 0; i < n; i++) cin >> adj[i];
        for(int i = 0; i < n; i++) edge[i].clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || adj[i][j] == '0') continue;
                edge[i].push_back(j);
            }
        }

        SCC.clear();
        ans.clear();
        memset(sedge, 0, sizeof(sedge));
        memset(finished, 0, sizeof(finished));
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        memset(sccn, 0, sizeof(sccn));
        SN = 0;
        for(int i = 0; i < n; i++) if(!clk[i]) dfs(i);

        for(int i = 0; i < SN; i++)
        {
            int prev = -1;
            if(SCC[i].size() == 1) continue;
            for(auto x : SCC[i])
            {
                if(prev != -1) ans.push_back({prev, x});
                prev = x;
            }
            ans.push_back({prev, SCC[i][0]});
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || adj[i][j] == '0' || sccn[i] == sccn[j]) continue;
                sedge[sccn[i]][sccn[j]] = true;
            }
        }

        for(int k = 0; k < SN; k++)
        {
            for(int i = 0; i < SN; i++)
            {
                for(int j = 0; j < SN; j++)
                {
                    if(sedge[i][j] && sedge[i][k] && sedge[k][j]) sedge[i][j] = false;
                }
            }
        }

        for(int i = 0; i < SN; i++)
        {
            for(int j = 0; j < SN; j++)
            {
                if(sedge[i][j])
                {
                    ans.push_back({SCC[i][0], SCC[j][0]});
                }
            }
        }

        cout << ans.size() << '\n';
        for(auto x : ans) cout << x.first+1 << ' ' << x.second+1 << '\n';
        cout << '\n';
    }

    return 0;
}
