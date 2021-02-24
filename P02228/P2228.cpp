#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

/*
dp[a][b] = [0, a]에서 b개의 구간을 골랐을 떄의 답
dp[a][b]는 b를 선택했을 때, 선택하지 않았을 때로 나뉨
선택하지 않은 경우 dp[a-1][b]와 같고, 선택한 경우, b부터 앞으로 구간을 길게 하며 계속 비교
둘 중 큰쪽이 dp[a][b]가 됨
*/

int n, m, a[100], dp[100][100];

int track(int tail, int interval)
{
    if(interval == 0) return 0;
    if(tail < 0) return -999999999;
    if(dp[tail][interval] != -1) return dp[tail][interval];

    dp[tail][interval] = track(tail-1, interval);

    int sum = 0;
    for(int i = tail; i >= 0; i--)
    {
        sum += a[i];
        dp[tail][interval] = max(dp[tail][interval], track(i-2, interval-1) + sum);
    }

    return dp[tail][interval];
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << track(n-1, m);

    return 0;
}
