#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, a[31], k, x;
bool dp[31][56565];

void f(int now, int w)
{
    if(now > n || dp[now][w]) return;
    dp[now][w] = true;
    f(now+1, w);
    f(now+1, w+a[now]);
    f(now+1, abs(w-a[now]));
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    f(0, 0);

    cin >> k;
    for(int z = 0; z < k; z++)
    {
        cin >> x;
        if(dp[n][x]) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}
