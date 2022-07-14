#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, x, y, len, ret, s, ans;
vector<pii> v[10001];
bool visited[10001];

void dfs(int i, int L)
{
    visited[i] = true;

    bool flag = false;
    for(auto next : v[i])
    {
        if(!visited[next.first])
        {
            flag = true;
            dfs(next.first, L + next.second);
        }
    }

    if(!flag && L > ret)
    {
        ret = L;
        s = i;
    }
}

int main()
{
    onlycc;
    cin >> n;
    while(!cin.eof())
    {
        cin >> x >> y >> len;
        v[x].push_back({y, len});
        v[y].push_back({x, len});
    }
    dfs(1, 0);

    ans = ret;
    ret = 0;
    memset(visited, 0, sizeof(visited));
    dfs(s, 0);

    if(s == 1) cout << ans;
    else cout << ret;


    return 0;
}
