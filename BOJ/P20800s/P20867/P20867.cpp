#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll m, s, g, l, r;
ld a, b, L, R;

int main()
{
    onlycc;
    cin >> m >> s >> g >> a >> b >> l >> r;
    L = l/a + m/(ld)g;
    R = r/b + m/(ld)s;
    cout << (L < R ? "friskus" : "latmask");

    return 0;
}
