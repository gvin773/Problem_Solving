#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define pii pair<int, int>
using namespace std;

typedef long long ll;

int n, m, lab[8][8], after[8][8], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, ans;
vector<pii> blank;

void dfs(int x, int y, int cnt)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(after[x][y] == 1) return;
    if(cnt && after[x][y] == 2) return;

    after[x][y] = 2;
    for(int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], 1);
}

int get_ans(pii x, pii y, pii z)
{
    lab[x.first][x.second] = 1;
    lab[y.first][y.second] = 1;
    lab[z.first][z.second] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) after[i][j] = lab[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(after[i][j] == 2) dfs(i, j, 0);

    int ret = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(after[i][j] == 0) ret++;

    lab[x.first][x.second] = 0;
    lab[y.first][y.second] = 0;
    lab[z.first][z.second] = 0;

    return ret;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> lab[i][j];
            if(lab[i][j] == 0) blank.push_back({i, j});
        }
    }

    for(pii i : blank) for(pii j : blank) for(pii k : blank)
        if(i != j && j != k && k != i) ans = max(ans, get_ans(i, j, k));

    cout << ans;

    return 0;
}
