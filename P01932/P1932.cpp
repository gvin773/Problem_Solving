#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int tri[501][501], dp[501][501], n;

int check(int line, int loc)
{
    if(dp[line][loc] != 0) return dp[line][loc];
    if(line == n) return dp[line][loc] = tri[line][loc];

    int ret = tri[line][loc];
    ret = max(ret+check(line+1, loc), ret+check(line+1, loc+1));

    return dp[line][loc] = ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> tri[i][j];

    cout << check(1, 1);

    return 0;
}
