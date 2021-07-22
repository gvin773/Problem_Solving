#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, dp[50001];

int cal(int x)
{
    if(dp[x] != 464646) return dp[x];

    int &ret = dp[x];
    for(int i = 1; i*i <= x; i++)
    {
        int temp = ret;
        ret = min(ret, 1+cal(x-i*i));
        if(ret > 4) ret = temp;
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++) dp[i] = 464646;
    dp[1] = 1;
    cout << cal(n);

    return 0;
}
