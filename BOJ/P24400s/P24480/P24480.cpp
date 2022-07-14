#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, r, u, v, ans[100001], cnt;
set<int> E[100001];
bool visited[100001];

void dfs(int now)
{
    visited[now] = true;
    ans[now] = ++cnt;
    for(auto x = E[now].rbegin(); x != E[now].rend(); x++) if(!visited[*x]) dfs(*x);
}

int main()
{
    onlycc;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        E[u].insert(v);
        E[v].insert(u);
    }
    dfs(r);
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}
