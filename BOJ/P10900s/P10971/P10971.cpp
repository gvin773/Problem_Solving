#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, w[10][10], ans = 46464646;
bool visited[10], started;

void dfs(int now, int money, int cnt)
{
    if(now == 0 && started == true)
    {
        ans = min(ans, money);
        return;
    }

    visited[now] = true;
    started = true;

    for(int i = 0; i < n; i++)
    {
        if(i == 0 && cnt == n-1 && w[now][i] != 0)
            dfs(i, money + w[now][i], cnt+1);

        if(!visited[i] && w[now][i] != 0)
        {
            dfs(i, money + w[now][i], cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];

    dfs(0, 0, 0);
    cout << ans;

    return 0;
}
