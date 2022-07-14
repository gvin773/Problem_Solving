#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, x, y, len, ret, s, ans;
vector<pii> v[100001];
bool visited[100001];

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
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        while(1)
        {
            cin >> y;
            if(y == -1) break;
            cin >> len;
            v[x].push_back({y, len});
        }
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
