#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, a, b, dp[1000001][2], p[1000001];
vector<int> edge[1000001];

int dfs(int now, int selected)
{
    if(dp[now][selected] != 987654321) return dp[now][selected];

    int &ret = dp[now][selected] = 1;
    if(selected)
    {
        for(auto next : edge[now])
        {
            if(p[now] == next) continue;
            p[next] = now;
            ret += min(dfs(next, 0), dfs(next, 1));
        }
    }
    else
    {
        ret = 0;
        for(auto next : edge[now])
        {
            if(p[now] == next) continue;
            p[next] = now;
            ret += dfs(next, 1);
        }
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) for(int j = 0; j < 2; j++) dp[i][j] = 987654321;
    cout << min(dfs(1, 1), dfs(1, 0));

    return 0;
}
