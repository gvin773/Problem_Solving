#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, dp[10001][10];
string s1 ,s2;
bool choose[10001][10];

int solve(int now, int offset)
{
    if(now == n) return 0;
    if(dp[now][offset] != -1) return dp[now][offset];

    int &ret = dp[now][offset] = 0;

    int L = ((int)(s1[now]-'0') + offset) % 10;
    if(L < 0) L = 10+L;
    int R = (int)(s2[now]-'0');

    int diff = L - R, t1, t2;
    if(diff < 0)
    {
        t1 = -diff + solve(now+1, (offset-diff)%10);
        t2 = 10+diff + solve(now+1, offset);
    }
    else
    {
        t1 = (10-diff)%10 + solve(now+1, (offset+10-diff)%10);
        t2 = diff + solve(now+1, offset);
    }

    if(t1 <= t2) choose[now][offset] = true;
    return ret += min(t1, t2);
}

void track(int now, int offset)
{
    if(now == n) return;

    int L = ((int)(s1[now]-'0') + offset) % 10;
    int R = (int)(s2[now]-'0');

    for(int i = 0; i < 10; i++)
    {
        if((L+i)%10 == R)
        {
            if(choose[now][offset])
            {
                cout << now+1 << ' ' << i << '\n';
                track(now+1, (offset+i)%10);
            }
            else
            {
                cout << now+1 << ' ' << i-10 << '\n';
                track(now+1, offset);
            }
            return;
        }
    }
}

int main()
{
    onlycc;
    cin >> n >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    track(0, 0);

    return 0;
}
