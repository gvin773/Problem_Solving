#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
#define MAX 10e9
using namespace std;

typedef long long ll;

int a[100000], dp[100000], n;

int psum(int start)
{
    if(start == n-1) dp[start] = a[start];
    if(dp[start] != 1001) return dp[start];

    int ret = a[start];
    ret = max(ret, ret + psum(start+1));

    dp[start] = ret;
    return ret;
}

int main()
{
    fill(dp, dp+100000, 1001);
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ret = -MAX;
    for(int i = 0; i < n; i++)
        ret = max(ret, psum(i));

    cout << ret;

    return 0;
}
