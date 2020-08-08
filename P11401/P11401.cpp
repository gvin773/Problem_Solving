#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll n, k, a = 1, b = 1, c = 1;

ll power(ll a, ll b)
{
    if(b == 0) return 1;
    if(b == 1) return a%MOD;

    ll ret = power(a, b/2);
    (ret *= ret) %= MOD;
    if(b % 2 == 1) (ret *= a) %= MOD;

    return ret;
}

int main()
{
    scanf("%lld%lld", &n, &k);

    for(int i = 2; i <= n; i++)
        a = ((a%MOD)*(i%MOD)) % MOD;

    for(int i = 2; i <= n-k; i++)
        b = ((b%MOD)*(i%MOD)) % MOD;

    for(int i = 2; i <= k; i++)
        c = ((c%MOD)*(i%MOD)) % MOD;

    b = ((b%MOD)*(c%MOD)) % MOD;

    printf("%lld", (a%MOD)*(power(b, MOD-2)%MOD)%MOD);

    return 0;
}
