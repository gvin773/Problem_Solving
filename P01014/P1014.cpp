#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int c, n, m, dp[10][1<<10];
string room[10];

bool seat_check(int start, int now)
{
    for(int i = 0; i < m; i++)
    {
        if(room[start][i] == 'x' && ((now>>i) & 1)) return false;
    }

    return true;
}

bool dir_check(int before, int now)
{
    for(int i = 0; i < m; i++)
    {
        int R = i-1, L = i+1;
        if((now>>i) & 1)
        {
            if(R >= 0 && ((before>>R) & 1)) return false;
            if(L < m && ((before>>L) & 1)) return false;
            if(R >= 0 && ((now>>R) & 1)) return false;
            if(L < m && ((now>>L) & 1)) return false;
        }
    }

    return true;
}

int get(int start, int state)
{
    if(start == n) return 0;
    if(dp[start][state] != -1) return dp[start][state];

    int &ret = dp[start][state] = 0;
    for(int now = 0; now < (1<<m); now++)
    {
        if(seat_check(start, now) && dir_check(state, now))
        {
            int cnt = 0;
            for(int x = 0; x < m; x++) if((now>>x)&1) cnt++;
            ret = max(ret, cnt + get(start+1, now));
        }
    }

    return ret;
}

int main()
{
    onlycc;
    cin >> c;
    for(int i = 0; i < c; i++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        for(int j = 0; j < n; j++) cin >> room[j];
        cout << get(0, 0) << '\n';
    }

    return 0;
}
