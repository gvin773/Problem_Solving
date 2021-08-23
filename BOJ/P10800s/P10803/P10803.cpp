#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int n, m, dp[10001][101];

int get_ans(int x, int y)
{
    if(dp[x][y] != -1) return dp[x][y];
    if(x%y == 0) return dp[x][y] = x/y;

    int &ret = dp[x][y] = 987654321;
    if(x > 3*y) ret = get_ans(x-y, y)+1;
    else
    {
        for(int i = 1; i <= x/2; i++) ret = min(ret, get_ans(i, y) + get_ans(x-i, y));
        for(int i = 1; i <= y/2; i++) ret = min(ret, get_ans(x, i) + get_ans(x, y-i));
    }
    return ret;
}

int main()
{
    onlycc;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= 100; i++) dp[i][i] = 1;
    if(n < m) swap(n, m);
    cout << get_ans(n, m);

    return 0;
}
