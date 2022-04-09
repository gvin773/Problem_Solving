#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n;
const int m = 1000000007;

ll ipow(ll a, ll b, ll c)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
        {
            ans *= a;
            ans %= c;
        }
        a = a*a % c;
        b /= 2;
    }
    return ans;
}

int main()
{
    onlycc;
    cin >> n;
    cout << (ipow(2, n+2, m) - (ll)5 + (ll)m) % m;

    return 0;
}
