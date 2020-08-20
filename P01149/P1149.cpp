#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int rgb[1000][3], dp[1000][3], n;

int check(int start, int color)
{
    if(dp[start][color] != 0) return dp[start][color];
    if(start == n-1) return dp[start][color] = rgb[start][color];

    int ret = rgb[start][color];
    if(color == 0)
        ret = min(ret+check(start+1, 1), ret+ check(start+1, 2));

    else if(color == 1)
        ret = min(ret+check(start+1, 0), ret+ check(start+1, 2));

    else if(color == 2)
        ret = min(ret+check(start+1, 0), ret+ check(start+1, 1));

    return dp[start][color] = ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> rgb[i][j];

    int ret = min({check(0, 0), check(0, 1), check(0, 2)});
    cout << ret;

    return 0;
}
