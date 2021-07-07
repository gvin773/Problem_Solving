#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

ll n, dp[101][1<<10][10], ans;
const ll MOD = 1000000000;

ll get_ans(int len, int state, int now)
{
    if(len == n) return (dp[len][state][now] = (state == (1<<10)-1) ? 1 : 0);
    if(dp[len][state][now] != -1) return dp[len][state][now];

    ll &ret = dp[len][state][now] = 0;
    if(now-1 >= 0)
    {
        ret += get_ans(len+1, state | 1<<(now-1), now-1);
        ret %= MOD;
    }
    if(now+1 <= 9)
    {
        ret += get_ans(len+1, state | 1<<(now+1), now+1);
        ret %= MOD;
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= 9; i++)
    {
        ans += get_ans(1, 1<<i, i);
        ans %= MOD;
    }
    cout << ans;

    return 0;
}
