#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

/*
일반적인 탐색으로는 TLE 발생
따라서 dp를 이용한다. dp[x][y][i]가 의미하는 것은 board[x][y]의 문자가 i번째 index로 쓰였을 때,
word를 완성할 수 있는 경우의 수이다.
*/

int n, m, k, ans, dp[100][100][100], a[4] = {0, 0, 1, -1}, b[4] = {1, -1, 0, 0};
string board[100], word;

int dfs(int x, int y, int index)
{
    if(index >= word.size()) return 0;
    if(dp[x][y][index] != -1) return dp[x][y][index];
    if(word[index] != board[x][y]) return 0;
    if(index == word.size()-1 && word[index] == board[x][y]) return 1;

    int &ret = dp[x][y][index] = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            int nx = x+a[i]*j, ny = y+b[i]*j;
            if(0 <= nx && nx < n && 0 <= ny && ny < m) ret += dfs(nx, ny, index+1);
        }
    }

    return ret;
}

int main()
{
    onlycc;
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> board[i];
    cin >> word;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans += dfs(i, j, 0);

    cout << ans;

    return 0;
}
