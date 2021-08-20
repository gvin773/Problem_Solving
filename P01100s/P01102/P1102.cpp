#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

int n, cost[16][16], p, dp[1<<16], s0;
string s;

void off_count(int state, vector<int> &v)
{
    for(int i = 0; i < n; i++) if(!((state>>i) & 1)) v.push_back(i);
}

int get_ans(int state)
{
    if(state == 0 && p != 0) return -1;
    if(dp[state] != -1) return dp[state];

    vector<int> v;
    off_count(state, v);
    if(n-v.size() >= p) return dp[state] = 0;

    int &ret = dp[state] = 987654321;
    for(int i = 0; i < n; i++)
    {
        if((state>>i) & 1) for(int j : v)
            ret = min(ret, cost[i][j] + get_ans(state | (1<<j)));
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> cost[i][j];

    cin >> s;
    for(int i = 0; i < n; i++) if(s[i] == 'Y') s0 |= (1<<i);

    cin >> p;
    memset(dp, -1, sizeof(dp));

    cout << get_ans(s0);

    return 0;
}
