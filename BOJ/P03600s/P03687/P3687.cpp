#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tc, n, dp[150][150][2], m[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll solve(int match, int digit, int head)
{
    ll &ret = dp[match][digit][head];
    if(dp[match][digit][head] != -1) return ret;
    if(match == 0 && digit == 0) return ret = 1;
    if(match != 0 && digit == 0) return ret = 0;
    if(digit == 1)
    {
        if(2 <= match && match <= 7) return ret = 1;
        else return ret = 0;
    }

    ret = 0;
    for(int i = 2; i <= 7; i++)
    {
        if(match-i < 0) break;
        if(solve(match-i, digit-1, 0))
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

void track(int match, int digit, int head)
{
    if(match == 0 || digit == 0) return;

    for(int i = 0; i < 10; i++)
    {
        if(i == 0 && head) continue;
        if(match >= m[i] && solve(match-m[i], digit-1, 0))
        {
            cout << i;
            track(match-m[i], digit-1, 0);
            break;
        }
    }
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        memset(dp, -1, sizeof(dp));

        int x = 1;
        while(1)
        {
            if(solve(n, x, 1)) break;
            x++;
        }

        track(n, x, 1);
        cout << ' ';

        if(n&1)
        {
            cout << 7;
            for(int i = 1; i < n/2; i++) cout << 1;
        }
        else for(int i = 0; i < n/2; i++) cout << 1;
        cout << '\n';
    }

    return 0;
}
