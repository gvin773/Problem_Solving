#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a[1111], dp[1111], before[1111], idx;
stack<ll> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    fill(dp, dp+n, 1);
    memset(before, -1, sizeof(before));
    for(int j = 0; j < n; j++)
    {
        for(int i = j+1; i < n; i++)
        {
            if(a[i] > a[j] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                before[i] = j;
            }
        }
    }

    for(int i = 1; i < n; i++) if(dp[idx] < dp[i]) idx = i;
    cout << dp[idx] << '\n';

    for(int i = idx; i != -1; i = before[i]) s.push(i);
    while(!s.empty())
    {
        cout << a[s.top()] << ' ';
        s.pop();
    }

    return 0;
}
