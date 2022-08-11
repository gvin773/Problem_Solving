#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, m, a, b, clk[30000], clkcnt, sccn[30000], SN;
vector<int> edge[30000];
stack<int> S;
bool finished[30000];
vector<vector<int>> SCC;
string str;

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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '.') continue;
            a = i+1;
            b = n+j+1;
            a = (a < 0 ? -(a+1)*2 : a*2-1);
            b = (b < 0 ? -(b+1)*2 : b*2-1);
            if(str[j] == '*')
            {
                edge[a&1 ? a-1 : a+1].push_back(b&1 ? b-1 : b+1);
                edge[b&1 ? b-1 : b+1].push_back(a&1 ? a-1 : a+1);
                edge[a].push_back(b);
                edge[b].push_back(a);
            }
            if(str[j] == '#')
            {
                edge[a&1 ? a-1 : a+1].push_back(b);
                edge[b&1 ? b-1 : b+1].push_back(a);
                edge[a].push_back(b&1 ? b-1 : b+1);
                edge[b].push_back(a&1 ? a-1 : a+1);
            }
        }
    }
    for(int i = 0; i < 2*(n+m); i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < n+m; i++)
    {
        if(sccn[i*2] == sccn[i*2+1])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;

    return 0;
}
