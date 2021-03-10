#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
dp[i][j] : 비용이 i일때, j번째 앱까지 사용하여 확보가능한 최대 메모리
*/

int n, m, dp[10001][100], M[100], c[100], sum;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> M[i];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        sum += c[i];
    }

    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i <= sum; i++)
        {
            if(i >= c[j] && j-1 < 0) dp[i][j] = max(dp[i][j], M[j]);
            if(i >= c[j]) dp[i][j] = max(dp[i][j], dp[i-c[j]][j-1]+M[j]);
            if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    for(int i = 0; i <= sum; i++)
    {
        if(dp[i][n-1] >= m)
        {
            cout << i;
            break;
        }
    }

    return 0;
}
