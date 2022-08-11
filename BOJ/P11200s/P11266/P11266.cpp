#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[10000], clkcnt, root;
vector<int> edge[10000];
stack<pii> S;
vector<vector<pii>> BCC;
set<int> ans;

ll dfs(int now, int prev = -1)
{
    clk[now] = ++clkcnt;

    int ret = clk[now], adjbcc = 0;
    bool leaf = true;
    for(auto next : edge[now])
    {
        if(prev == next) continue;
        leaf = false;
        if(clk[now] > clk[next]) S.push({now, next});
        if(clk[next] > 0) ret = min(ret, clk[next]);
        else
        {
            adjbcc++;
            int temp = dfs(next, now);
            ret = min(ret, temp);
            if(temp >= clk[now])
            {
                if(now != root) ans.insert(now);
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
    if(now == root && adjbcc > 1 && ret == clk[now] && !leaf) ans.insert(now);

    return ret;
}

int main()
{
    onlycc;
    cin >> V >> E;
    while(E--)
    {
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    for(int i = 0; i < V; i++) if(!clk[i]) root = i, dfs(i);

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x+1 << ' ';

    return 0;
}
