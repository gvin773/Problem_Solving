#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, r, u, v, ans[100001], cnt;
set<int> E[100001];
bool visited[100001];
queue<int> q;

void bfs()
{
    visited[r] = true;
    q.push(r);
    ans[r] = ++cnt;

    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            q.pop();
            for(auto x : E[now])
            {
                if(!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                    ans[x] = ++cnt;
                }
            }
        }
    }
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
    bfs();
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}
