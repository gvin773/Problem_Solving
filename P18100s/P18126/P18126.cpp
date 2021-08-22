#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n, a, b, c, ans;
vector<pii> v[5001];
bool visited[5001];

void dfs(int now, ll len)
{
    ans = max(ans, len);
    visited[now] = true;

    for(int i = 0; i < v[now].size(); i++)
    {
        len += v[now][i].second;
        if(!visited[v[now][i].first]) dfs(v[now][i].first, len);
        len -= v[now][i].second;
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, 0);
    cout << ans;

    return 0;
}
