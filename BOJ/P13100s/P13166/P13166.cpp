#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAX 800001
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, range, p[MAX][4], clkcnt, clk[MAX], sccn[MAX], SN;
vector<int> ks, edge[MAX];
stack<int> S;
bool finished[MAX], visited[MAX];

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

inline void OR(int A, int B, int mid)
{
    edge[A&1 ? A-1 : A+1].push_back(B);
    edge[B&1 ? B-1 : B+1].push_back(A);
}

int main()
{
    onlycc;
    cin >> n;
    range = 2*n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++) cin >> p[i][j];
        ks.push_back(p[i][1]);
        ks.push_back(p[i][3]);
    }
    ks.erase(unique(ks.begin(), ks.end()), ks.end());
    sort(ks.begin(), ks.end());

    int lo = -1, hi = ks.size();
    while(lo+1 < hi)
    {
        int mid = (lo+hi) / 2;
        for(int i = 0; i < n; i++)
        {
            int X = -1, Y = -1;

            if(p[i][1] <= ks[mid])
            {
                if(!visited[p[i][0]]) X = p[i][0]*2-1;
                else X = p[i][0]*2-2;
                visited[p[i][0]] = true;
            }
            if(p[i][3] <= ks[mid])
            {
                if(!visited[p[i][2]]) Y = p[i][2]*2-1;
                else Y = p[i][2]*2-2;
                visited[p[i][2]] = true;
            }

            if(X == -1 && Y == -1)
            {
                lo = mid;
                goto xy;
            }
            if(X == -1) X = Y;
            if(Y == -1) Y = X;
            OR(X, Y, mid);
        }
        for(int i = 0; i < 2*range; i++) if(!clk[i]) dfs(i);

        for(int i = 0; i < range; i++)
        {
            if(sccn[i*2] == sccn[i*2+1])
            {
                lo = mid;
                goto xy;
            }
        }
        hi = mid;
        xy:
            clkcnt = 0;
            memset(clk, 0, 4*n*sizeof(int));
            memset(sccn, 0, 4*n*sizeof(int));
            SN = 0;
            for(int i = 0; i < 4*n; i++) edge[i].clear();
            while(!S.empty()) S.pop();
            memset(finished, 0, 4*n*sizeof(bool));
            memset(visited, 0, 4*n*sizeof(bool));
    }
    cout << (hi >= ks.size() ? -1 : ks[hi]);

    return 0;
}
