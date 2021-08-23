#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, m, n, k, ret;
bool arr[50][50], check[50][50];

int dfs(int x, int y)
{
    if(arr[x][y] == false || check[x][y] == true) return 0;

    check[x][y] = true;
    int temp;
    if(x != 0 && arr[x-1][y] == true && check[x-1][y] == false) temp = dfs(x-1, y);
    if(x != m-1 && arr[x+1][y] == true && check[x+1][y] == false) temp = dfs(x+1, y);
    if(y != 0 && arr[x][y-1] == true && check[x][y-1] == false) temp = dfs(x, y-1);
    if(y != n-1 && arr[x][y+1] == true && check[x][y+1] == false) temp = dfs(x, y+1);

    return 1;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        ret = 0;
        cin >> m >> n >> k;
        for(int j = 0; j < m; j++)
            for(int l = 0; l < n; l++)
            {
                arr[j][l] = false;
                check[j][l] = false;
            }

        for(int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            arr[a][b] = true;
        }

        for(int j = 0; j < m; j++)
            for(int l = 0; l < n; l++)
                ret += dfs(j, l);

        cout << ret << '\n';
    }

    return 0;
}
