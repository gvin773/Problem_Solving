#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

/*
dp[a][b] = [0, a]���� b���� ������ ����� ���� ��
dp[a][b]�� b�� �������� ��, �������� �ʾ��� ���� ����
�������� ���� ��� dp[a-1][b]�� ����, ������ ���, b���� ������ ������ ��� �ϸ� ��� ��
�� �� ū���� dp[a][b]�� ��
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
