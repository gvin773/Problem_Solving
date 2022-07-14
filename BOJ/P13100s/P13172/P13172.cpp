#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll m, n, s, sum;

ll ipow(ll a, ll b)
{
    if(b == 0) return 1;

    ll x = ipow(a, b/2)%MOD;
    if(b&1) return (((x*x)%MOD)*a)%MOD;
    else return (x*x)%MOD;
}

int main()
{
    onlycc;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> n >> s;
        ll temp = s * (ipow(n,MOD-2)%MOD) % MOD;
        sum = (sum + temp) % MOD;
    }
    cout << sum;

    return 0;
}
