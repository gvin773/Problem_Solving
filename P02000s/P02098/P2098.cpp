#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
const int INF = 10e8;

int n, w[16][16], dp[16][1<<16];

int TSP(int cur, int visited)
{
    if(dp[cur][visited] != -1) return dp[cur][visited];
    if(visited == (1<<n)-1)
    {
        if(w[cur][0] != 0) return w[cur][0];
        return INF;
    }

    int &ret = dp[cur][visited] = INF;
    for(int i = 0; i < n; i++)
    {
        if(!(visited & (1<<i)) && w[cur][i] != 0)
            ret = min(ret, TSP(i, visited | (1<<i)) + w[cur][i]);
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> w[i][j];

    memset(dp, -1, sizeof(dp));
    cout << TSP(0, 1);

    return 0;
}
