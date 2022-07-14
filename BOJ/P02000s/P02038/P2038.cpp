#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, f[9000000], lo = 1, hi = 1;

int main()
{
    onlycc;
    cin >> n;

    f[lo++] = 1;
    while(hi < n)
    {
        f[lo] = 1 + f[lo - f[f[lo-1]]];
        hi += f[lo++];
    }
    cout << lo-1;

    return 0;
}
