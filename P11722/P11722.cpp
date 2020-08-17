#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a[1000], dp[1000];

int lis(int start)
{
    if(dp[start] != -1) return dp[start];

    int ret = 1;
    for(int i = start+1; i < n; i++)
    {
        if(a[start] > a[i])
            ret = max(ret, 1 + lis(i));
    }

    dp[start] = ret;

    return ret;
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
