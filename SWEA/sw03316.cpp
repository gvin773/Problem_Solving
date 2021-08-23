#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int t, n, dp[1<<4][10001]; //state, day
string p;

int get_ans(int state, int day)
{
    if(day == n) return 1;
    if(dp[state][day] != -1) return dp[state][day];

    int &ret = dp[state][day] = 0;
    for(int next = 1; next < (1<<4); next++)
    {
        if(((next>>(p[day]-'A')) & 1) == 0) continue;

        bool flag = false;
        for(int x = 0; x < 4; x++)
        {
            if(((state>>x) & (next>>x)) & 1)
            {
                ret = (ret%MOD + get_ans(next, day+1)%MOD)%MOD;
                flag = true;
            }
            if(flag == true) break;
        }
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> p;
        n = p.size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int state = 1; state < (1<<4); state++)
        {
            if((state & 1) == 0) continue;
            if((state>>(p[0]-'A') & 1) == 0) continue;
            ans = (ans%MOD + get_ans(state, 1)%MOD)%MOD;
        }

        cout << "#" << i+1 << ' ' << ans << '\n';
    }

    return 0;
}
