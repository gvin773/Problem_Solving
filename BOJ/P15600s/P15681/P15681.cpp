#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, r, q, a, b, dp[100001];
vector<int> edge[100001];
bool visited[100001];

int dfs(int now)
{
    if(dp[now] != -1) return dp[now];

    int &ret = dp[now] = 1;
    visited[now] = true;
    for(auto next : edge[now])
    {
        if(visited[next]) continue;
        ret += dfs(next);
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n >> r >> q;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    dfs(r);

    for(int i = 0; i < q; i++)
    {
        cin >> a;
        cout << dp[a] << '\n';
    }

    return 0;
}
