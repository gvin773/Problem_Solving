#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, l, r;

int main()
{
    onlycc;
    cin >> x >> l >> r;
    if(x < l) cout << l;
    else if(r < x) cout << r;
    else cout << x;

    return 0;
}
