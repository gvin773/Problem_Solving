#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll t, e, dp[5001], ans;

ll get_ans(int now)
{
    if(dp[now] != 0) return dp[now];

    ll &ret = dp[now] = 0;
    ret = 2*get_ans(now-1)%MOD;
    for(int i = 0; i <= now-2; i++)
    {
        ret += (get_ans(i)%MOD * get_ans(now-2-i)%MOD) % MOD;
        ret %= MOD;
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        ans = 0;
        dp[0] = 1, dp[1] = 2, dp[2] = 5;
        cin >> e;
        cout << get_ans(e) << '\n';
    }

    return 0;
}
