#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, m, x, y, arr[2000], dp[2000][2000];

bool f(int a, int b)
{
    if(a >= b) return 1;
    if(dp[a][b] != -1) return dp[a][b];

    return dp[a][b] = (arr[a] == arr[b]) && f(a+1, b-1);
}

int main()
{
    onlycc;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        cout << f(x-1, y-1) << '\n';
    }

    return 0;
}
