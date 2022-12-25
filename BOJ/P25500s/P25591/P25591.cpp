#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, y, a, b, c, d, q, r;

int main()
{
    onlycc;
    cin >> x >> y;
    cout << (a = 100-x) << ' ' << (b = 100-y) << ' ';
    cout << (c = 100-(a+b)) << ' ' << (d = a*b) << ' ';
    cout << (q = d/100) << ' ' << (r = d%100) << '\n';
    cout << c+q << ' ' << r;

    return 0;
}
