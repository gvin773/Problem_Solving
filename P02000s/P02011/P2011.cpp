#define onlycc ios_base::sync_with_stdio(0);cin.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#define MOD 1000000
using namespace std;

typedef long long ll;

string code;
ll dp[5001], len;

ll check(int start)
{
    if(start > len) return 0;
    if(start == len) return 1;
    if(dp[start] != -1) return dp[start];

    ll ret = 0;
    if(code[start] != '0')
        ret = (check(start+1)%MOD) % MOD;

    ll num = (code[start]-'0')*10 + code[start+1]-'0';
    if(start != len-1 && (10 <= num && num <= 26))
        ret = (ret%MOD + check(start+2)%MOD) % MOD;

    return dp[start] = ret;
}

int main()
{
    fill(dp, dp+5001, -1);
    onlycc;
    cin >> code;
    len = code.size();

    cout << check(0);

    return 0;
}
