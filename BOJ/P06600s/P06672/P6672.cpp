#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[10000], clkcnt, root, cnt[10000], cc;
vector<int> edge[10000];
stack<pii> S;
vector<vector<pii>> BCC;
set<int> ans;

ll dfs(int now, int prev = -1)
{
    clk[now] = ++clkcnt;

    int ret = clk[now], adjbcc = 0;
    for(auto next : edge[now])
    {
        if(prev == next) continue;
        if(clk[now] > clk[next]) S.push({now, next});
        if(clk[next] > 0) ret = min(ret, clk[next]);
        else
        {
            adjbcc++;
            int temp = dfs(next, now);
            ret = min(ret, temp);
            if(temp >= clk[now])
            {
                cnt[now]++;
                if(prev != -1) ans.insert(now);
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
    if(prev == -1) ans.insert(now);
    if(ans.find(now) != ans.end() && now != root) cnt[now]++;

    return ret;
}

int main()
{
    onlycc;
    while(1)
    {
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        memset(cnt, 0, sizeof(cnt));
        cc = 0;
        for(int i = 0; i < V; i++) edge[i].clear();
        while(!S.empty()) S.pop();
        BCC.clear();
        ans.clear();
        cin >> V >> E;
        if(V == 0 && E == 0) break;
        while(E--)
        {
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(int i = 0; i < V; i++) if(!clk[i]) root = i, dfs(i), cc++;

        int M = 0;
        for(auto x : ans) M = max(M, cnt[x]);
        cout << M + cc-1 << '\n';
    }

    return 0;
}
