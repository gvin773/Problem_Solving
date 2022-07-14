#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll k, dp[5000], psum[5000] = {0, 1, 2, }, n;

ll number(int x)
{
    if(dp[x] != -1) return dp[x];
    if(x <= 2) return dp[x] = 1;

    dp[x] = number(x-1) + number(x-2);
    psum[x] = psum[x-1] + dp[x];
    return dp[x];
}

void track(int x, ll kth)
{
    if(x == 0) return;

    ll pivot = psum[x-1];
    if(pivot < kth)
    {
        cout << 1;
        track(x-1, kth-pivot-1);
    }
    else
    {
        cout << 0;
        track(x-1, kth);
    }
}

int main()
{
    onlycc;
    cin >> k;
    memset(dp, -1, sizeof(dp));
    if(k == 1) cout << 1;
    else
    {
        number(3000);
        for(int i = 1; i < 3000; i++)
        {
            if(psum[i] >= k)
            {
                n = i;
                break;
            }
        }
        track(n, k);
    }

    return 0;
}
