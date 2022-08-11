#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int tc, n, m, k, a, b, c, d, clk[4000], clkcnt, sccn[4000], SN;
vector<int> edge[4000];
stack<int> S;
bool finished[4000];
vector<vector<int>> SCC;

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

inline void OR(int A, int B)
{
    edge[A&1 ? A-1 : A+1].push_back(B);
    edge[B&1 ? B-1 : B+1].push_back(A);
}

inline void claues(int A, int B, int C, int D)
{
    OR(A, C);
    OR(B, C);
    OR(A, D);
    OR(B, D);
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        memset(clk, 0, sizeof(clk));
        clkcnt = 0;
        memset(sccn, 0, sizeof(sccn));
        SN = 0;
        for(int i = 0; i < 4000; i++) edge[i].clear();
        while(!S.empty()) S.pop();
        memset(finished, 0, sizeof(finished));
        SCC.clear();
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> a >> b >> c >> d;
            if(a == c && b == d) continue;
            if(a == c)
            {
                a = (a < 0 ? -(a+1)*2 : a*2-1);
                if(b < d) OR(a, a);
                else OR(a&1 ? a-1 : a+1, a&1 ? a-1 : a+1);
            }
            else if(b == d)
            {
                b += n;
                b = (b < 0 ? -(b+1)*2 : b*2-1);
                if(a < c) OR(b, b);
                else OR(b&1 ? b-1 : b+1, b&1 ? b-1 : b+1);
            }
            else
            {
                a = (a < 0 ? -(a+1)*2 : a*2-1);
                b += n;
                b = (b < 0 ? -(b+1)*2 : b*2-1);
                c = (c < 0 ? -(c+1)*2 : c*2-1);
                d += n;
                d = (d < 0 ? -(d+1)*2 : d*2-1);

                if(a < c && b < d) claues(a, d, b, c);
                else if(a < c && b > d) claues(a&1 ? a-1 : a+1, d, b, c&1 ? c-1 : c+1);
                else if(a > c && b > d) claues(a&1 ? a-1 : a+1, d&1 ? d-1 : d+1, b&1 ? b-1 : b+1, c&1 ? c-1 : c+1);
                else claues(a, d&1 ? d-1 : d+1, b&1 ? b-1 : b+1, c);
            }
        }
        for(int i = 0; i < 2*(n+m); i++) if(!clk[i]) dfs(i);

        for(int i = 0; i < n+m; i++)
        {
            if(sccn[i*2] == sccn[i*2+1])
            {
                cout << "No\n";
                goto xy;
            }
        }
        cout << "Yes\n";
        xy:;
    }

    return 0;
}
