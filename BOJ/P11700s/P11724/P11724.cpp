#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, m, ret;
vector<int> ver[1001];
bool visited[1001];

void dfs(int cur)
{
    if(visited[cur] == true) return;
    visited[cur] = true;
    for(int i = 0; i < ver[cur].size(); i++) dfs(ver[cur][i]);
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;
        ver[st].push_back(en);
        ver[en].push_back(st);
    }

    for(int i = 1; i <= n; i++)
        if(!visited[i])
        {
            dfs(i);
            ret++;
        }

    cout << ret;

    return 0;
}
