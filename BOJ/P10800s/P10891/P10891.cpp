#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int V, E, a, b, clk[100000], clkcnt, root, cnt[100000], bnum[100000], BN;
vector<int> edge[100000];
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
    cin >> V >> E;
    while(E--)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 0; i < V; i++) if(!clk[i]) root = i, dfs(i);

    bool flag[100000] = {};
    for(auto cc : BCC)
    {
        BN++;
        if(cc.size() == 1) continue;

        unordered_set<int> v;
        for(auto e : cc)
        {
            v.insert(e.first);
            v.insert(e.second);
            bnum[e.first] = BN;
            bnum[e.first] = BN;
        }
        if(cc.size() != v.size())
        {
            cout << "Not cactus";
            return 0;
        }
        for(auto x : v)
        {
            if(flag[x])
            {
                cout << "Not cactus";
                return 0;
            }
            flag[x] = true;
        }
    }
    cout << "Cactus";

    return 0;
}
