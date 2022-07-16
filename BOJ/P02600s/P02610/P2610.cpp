#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, k, d[200][200], a, b, s, cnt;
vector<ll> edge[200], meeting[200], v;
bool visited[200];

void dfs(int now)
{
    meeting[cnt].push_back(now);
    visited[now] = true;
    for(auto x : edge[now]) if(!visited[x]) dfs(x);
}

int main()
{
    onlycc;
    cin >> n >> k;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 10000000000LL;
    for(int i = 0; i < k; i++)
    {
        cin >> a >> b;
        d[a-1][b-1] = 1;
        d[b-1][a-1] = 1;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++)
    {
        ll ret = 10000000000LL, ans;
        for(int j = 0; j < meeting[i].size(); j++)
        {
            ll M = 0;
            for(int k = 0; k < meeting[i].size(); k++)
            {
                if(j == k) continue;
                M = max(M, d[meeting[i][k]][meeting[i][j]]);
            }
            if(M < ret)
            {
                ret = M;
                ans = meeting[i][j];
            }
        }
        v.push_back(ans+1);
    }
    sort(v.begin(), v.end());
    for(auto x : v) cout << x << '\n';

    return 0;
}
