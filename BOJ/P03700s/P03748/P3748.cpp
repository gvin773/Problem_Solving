#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, m, a, b, clk[100000], clkcnt, BN, start[100000];
vector<int> edge[100000];
stack<pii> S;
unordered_set<int> cc[100000], ans;

ll dfs(int now, int prev = -1)
{
    clk[now] = ++clkcnt;

    int ret = clk[now];
    for(auto &next : edge[now])
    {
        if(prev == next) continue;
        if(clk[now] > clk[next]) S.push({now, next});
        if(clk[next] > 0) ret = min(ret, clk[next]);
        else
        {
            int temp = dfs(next, now);
            ret = min(ret, temp);
            if(temp >= clk[now])
            {
                while(!S.empty() && S.top() != make_pair(now, next))
                {
                    cc[S.top().first].insert(BN);
                    cc[S.top().second].insert(BN);
                    S.pop();
                }
                cc[S.top().first].insert(BN);
                cc[S.top().second].insert(BN);
                start[BN] = now;
                S.pop();

                BN++;
            }
        }
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        BN = 0;
        memset(start, 0, sizeof(start));
        for(int i = 0; i < n; i++) edge[i].clear();
        while(!S.empty()) S.pop();
        for(int i = 0; i < n; i++) cc[i].clear();
        ans.clear();

        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            edge[a-1].push_back(b-1);
            edge[b-1].push_back(a-1);
        }

        for(int i = 0; i < n; i++) if(!clk[i]) dfs(i);

        bool visited[100000] = {};
        int L[100000] = {};
        for(int i = 0; i < BN; i++)
        {
            bool flag = false;
            queue<int> q;
            unordered_set<int> check;

            visited[start[i]] = true;
            q.push(start[i]);
            check.insert(start[i]);

            int level = 1;
            L[start[i]] = 0;
            vector<int> v;
            while(!q.empty())
            {
                int Size = q.size();
                for(int z = 0; z < Size; z++)
                {
                    int now = q.front();
                    q.pop();
                    v.push_back(now);

                    for(auto x : edge[now])
                    {
                        if(cc[x].find(i) == cc[x].end()) continue;
                        if(!visited[x] || (cc[x].size() > 1 && check.find(x) == check.end()))
                        {
                            check.insert(x);
                            visited[x] = true;
                            q.push(x);
                            L[x] = level;
                        }
                        if(L[now] == L[x]) flag = true;
                    }
                }
                level++;
            }

            if(flag) for(auto &x : v) ans.insert(x);
        }

        cout << ans.size() << '\n';
    }

    return 0;
}
