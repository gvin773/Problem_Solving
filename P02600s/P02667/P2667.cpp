#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, num;
string arr[25];
bool visited[25][25];

int dfs(int x, int y)
{
    if(visited[x][y] == true || arr[x][y] == '0') return 0;

    visited[x][y] = true;
    int ret = 1;
    if(x > 0) ret += dfs(x-1, y);
    if(y > 0) ret += dfs(x, y-1);
    if(x < n-1) ret += dfs(x+1, y);
    if(y < n-1) ret += dfs(x, y+1);

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans[500] = {}, cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!visited[i][j] && arr[i][j] == '1')
            {
                num++;
                ans[cnt++] = dfs(i, j);
            }

    sort(ans, ans+cnt);
    cout << num << '\n';
    for(int i = 0; i < cnt; i++)
        if(ans[i]) cout << ans[i] << '\n';

    return 0;
}
