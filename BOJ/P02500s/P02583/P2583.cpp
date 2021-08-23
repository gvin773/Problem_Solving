#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, k, num;
bool arr[100][100], visited[100][100];

int dfs(int x, int y)
{
    if(visited[x][y] == true || arr[x][y] == true) return 0;

    visited[x][y] = true;
    int ret = 1;
    if(x > 0) ret += dfs(x-1, y);
    if(y > 0) ret += dfs(x, y-1);
    if(x < n-1) ret += dfs(x+1, y);
    if(y < m-1) ret += dfs(x, y+1);

    return ret;
}

int main()
{
    onlycc;
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for(int x = lx; x < rx; x++)
            for(int y = ly; y < ry; y++)
                arr[x][y] = true;
    }

    int ans[5555] = {}, cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j] && arr[i][j] == false)
            {
                num++;
                ans[cnt++] = dfs(i, j);
            }

    sort(ans, ans+cnt);
    cout << num << '\n';
    for(int i = 0; i < cnt; i++)
        if(ans[i]) cout << ans[i] << ' ';

    return 0;
}
