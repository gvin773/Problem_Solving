#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a[1000], dp[1000];

int lis(int start)
{
    if(start == n-1) return dp[n-1] = a[n-1];
    if(start == n) return 0;
    if(dp[start] != -1) return dp[start];

    int maxv = a[start];

    for(int i = start+1; i < n; i++)
    {
        int ret = a[start];
        if(a[start] < a[i])
        {
            ret += lis(i);
            maxv = max(maxv, ret);
        }
    }

    dp[start] = maxv;

    return maxv;
}

int main()
{
    fill(dp, dp+1000, -1);
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ret = 0;
    for(int i = 0; i < n; i++)
        ret = max(ret, lis(i));

    cout << ret;

    return 0;
}
