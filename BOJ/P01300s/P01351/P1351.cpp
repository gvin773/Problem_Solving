#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, p, q;
unordered_map<ll, ll> m;

ll f(ll x)
{
    if(m.find(x) != m.end()) return m[x];

    ll ret = f(x/p) + f(x/q);
    return m[x] = ret;
}

int main()
{
    onlycc;
    cin >> n >> p >> q;
    m[0] = 1;
    cout << f(n);

    return 0;
}
