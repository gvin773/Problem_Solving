#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, m, a, b, ans;
vector<int> c[101];
bool visited[101];

void dfs(int now)
{
    visited[now] = true;
    ans++;
    for(int i = 0; i < c[now].size(); i++)
    {
        if(!visited[c[now][i]]) dfs(c[now][i]);
    }
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    dfs(1);
    cout << ans-1;

    return 0;
}
