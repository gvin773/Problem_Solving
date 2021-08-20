#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, arr[100][100], M = -46, ans = -46;

void dfs(int x, int y, int rain, bool visited[][100])
{
    if(arr[x][y] <= rain || visited[x][y] == true) return;

    visited[x][y] = true;

    if(x != 0) dfs(x-1, y, rain, visited);
    if(y != 0) dfs(x, y-1, rain, visited);
    if(x != n-1) dfs(x+1, y, rain, visited);
    if(y != n-1) dfs(x, y+1, rain, visited);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            M = max(M, arr[i][j]);
        }

    for(int i = 0; i <= M; i++)
    {
        int temp = 0;
        bool visited[100][100] = {};
        for(int x = 0; x < n; x++)
            for(int y = 0; y < n; y++)
                if(visited[x][y] == false && arr[x][y] > i)
                {
                    temp++;
                    dfs(x, y, i, visited);
                }

        ans = max(ans, temp);
    }

    cout << ans;

    return 0;
}
