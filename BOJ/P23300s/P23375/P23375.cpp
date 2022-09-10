#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, y, r;

int main()
{
    onlycc;
    cin >> x >> y >> r;
    cout << x-r << ' ' << y-r << '\n';
    cout << x-r << ' ' << y+r << '\n';
    cout << x+r << ' ' << y+r << '\n';
    cout << x+r << ' ' << y-r;

    return 0;
}
