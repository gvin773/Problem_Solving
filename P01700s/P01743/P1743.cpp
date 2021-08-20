#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, k;
bool arr[101][101], visited[101][101];

int dfs(int x, int y)
{
    if(visited[x][y] == true || arr[x][y] == false) return 0;

    visited[x][y] = true;
    int ret = 1;
    if(x > 1) ret += dfs(x-1, y);
    if(y > 1) ret += dfs(x, y-1);
    if(x < n) ret += dfs(x+1, y);
    if(y < m) ret += dfs(x, y+1);

    return ret;
}

int main()
{
    onlycc;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = true;
    }

    int ans = -100;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));

    cout << ans;

    return 0;
}
