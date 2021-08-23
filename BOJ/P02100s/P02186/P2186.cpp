#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

/*
�Ϲ����� Ž�����δ� TLE �߻�
���� dp�� �̿��Ѵ�. dp[x][y][i]�� �ǹ��ϴ� ���� board[x][y]�� ���ڰ� i��° index�� ������ ��,
word�� �ϼ��� �� �ִ� ����� ���̴�.
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
