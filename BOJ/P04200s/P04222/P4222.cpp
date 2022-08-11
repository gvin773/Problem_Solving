#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a, b, clk[110000], clkcnt, root, BN, shaft, num;
vector<ll> edge[110000];
stack<pll> S;
vector<vector<pll>> BCC;
unordered_set<ll> ans, bnum[110000], cc[110000];

ll dfs(ll now, ll prev = -1)
{
    clk[now] = ++clkcnt;

    ll ret = clk[now], adjbcc = 0;
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
            ll temp = dfs(next, now);
            ret = min(ret, temp);
            if(temp >= clk[now])
            {
                if(now != root) ans.insert(now);
                vector<pll> v;
                while(!S.empty() && S.top() != make_pair(now, next))
                {
                    v.push_back(S.top());
                    cc[S.top().first].insert(BN);
                    cc[S.top().second].insert(BN);
                    bnum[BN].insert(S.top().first);
                    bnum[BN].insert(S.top().second);
                    S.pop();
                }
                v.push_back(S.top());
                cc[S.top().first].insert(BN);
                cc[S.top().second].insert(BN);
                bnum[BN].insert(S.top().first);
                bnum[BN].insert(S.top().second);
                S.pop();

                BCC.push_back(v);
                BN++;
            }
        }
    }
    if(now == root && adjbcc > 1 && ret == clk[now] && !leaf) ans.insert(now);

    return ret;
}

int main()
{
    onlycc;
    for(int tc = 1; ; tc++)
    {
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        BN = 0;
        shaft = 0;
        num = 1;
        for(int i = 0; i < 110000; i++) edge[i].clear();
        while(!S.empty()) S.pop();
        BCC.clear();
        ans.clear();
        for(int i = 0; i < 110000; i++) bnum[i].clear();
        for(int i = 0; i < 110000; i++) cc[i].clear();
        ll Max = 0;
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b;
            edge[a-1].push_back(b-1);
            edge[b-1].push_back(a-1);
            Max = max(Max, max(a, b));
        }

        for(int i = 0; i < Max; i++)
        {
            if(!clk[i])
            {
                root = i;
                dfs(i);
            }
        }

        ll pnum[110000] = {};
        for(auto x : ans) for(auto c : cc[x]) pnum[c]++;

        for(int i = 0; i < BN; i++)
        {
            if(pnum[i] == 1)
            {
                shaft++;
                num *= (ll)((ll)bnum[i].size()-1);
            }
        }

        cout << "Case " << tc << ": ";
        if(shaft) cout << shaft <<' ' << num << '\n';
        else cout << 2 << ' ' << Max*(Max-1)/2 << '\n';
    }

    return 0;
}
