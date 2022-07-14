#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, value[10001], a, b, dp[10001][2], p[10001];
vector<int> edge[10001];

int dfs(int now, int selected)
{
    if(dp[now][selected] != -1) return dp[now][selected];

    int &ret = dp[now][selected] = value[now];
    if(selected)
    {
        for(auto next : edge[now])
        {
            if(p[now] == next) continue;
            p[next] = now;
            ret += dfs(next, 0);
        }
    }
    else
    {
        ret = 0;
        for(auto next : edge[now])
        {
            if(p[now] == next) continue;
            p[next] = now;
            ret += max(dfs(next, 0), dfs(next, 1));
        }
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> value[i];
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    cout << max(dfs(1, 1), dfs(1, 0));

    return 0;
}
