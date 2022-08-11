#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int k, n, l[3], clkcnt, clk[10000], sccn[10000], SN, ret[10000];
char c[3];
vector<int> edge[10000];
stack<int> S;
bool finished[10000];

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
        while(1)
        {
            int x = S.top();
            S.pop();
            sccn[x] = SN;
            finished[x] = true;

            if(now == x) break;
        }
        SN++;
    }

    return ret;
}

inline void OR(int A, int B)
{
    edge[A&1 ? A-1 : A+1].push_back(B);
    if(A != B) edge[B&1 ? B-1 : B+1].push_back(A);
}

int main()
{
    onlycc;
    cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++) cin >> l[j] >> c[j];
        for(int j = 0; j < 3; j++)
        {
            int a = c[j] == 'R' ? l[j]*2-2 : l[j]*2-1;
            int k = (j+1)%3;
            int b = c[k] == 'R' ? l[k]*2-2 : l[k]*2-1;
            OR(a, b);
        }
    }
    for(int i = 0; i < 2*k; i++) if(!clk[i]) dfs(i);

    for(int i = 0; i < k; i++)
    {
        if(sccn[i*2] == sccn[i*2+1])
        {
            cout << -1;
            return 0;
        }
    }

    pii P[10000];
    for(int i = 0; i < 2*k; i++) P[i] = {sccn[i], i};
    sort(P, P+2*k);

    memset(ret, -1, sizeof(ret));
    for(int i = 2*k-1; i >= 0; i--)
    {
        int now = P[i].second;
        if(ret[now/2] == -1) ret[now/2] = !(now&1);
    }
    for(int i = 0; i < k; i++) cout << (ret[i] ? 'B' : 'R');

    return 0;
}
