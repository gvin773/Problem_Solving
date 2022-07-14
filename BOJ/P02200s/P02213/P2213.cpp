#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, w[10001], dp[10001][2], a, b, p[10001];
vector<ll> e[10001], ans;
bool choose[10001][2];

int solve(int now, bool c)
{
    if(dp[now][c] != -1) return dp[now][c];

    ll &ret = dp[now][c], t1 = 0, t2 = 0;
    for(auto next : e[now])
    {
        if(p[now] == next) continue;
        p[next] = now;
        t1 += solve(next, 0);
    }
    if(!c)
    {
        t2 += w[now];
        for(auto next : e[now])
        {
            if(p[now] == next) continue;
            p[next] = now;
            t2 += solve(next, 1);
        }
    }
    if(t2 > t1) choose[now][c] = true;

    return ret = max(t1, t2);
}

void track(int now, bool c)
{
    if(choose[now][c])
    {
        ans.push_back(now);
        for(auto next : e[now])
        {
            if(p[now] == next) continue;
            track(next, 1);
        }
    }
    else
    {
        for(auto next : e[now])
        {
            if(p[now] == next) continue;
            track(next, 0);
        }
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0) << '\n';
    track(1, 0);
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout << i << ' ';

    return 0;
}
