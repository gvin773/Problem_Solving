#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, x, b, y, t;

int main()
{
    onlycc;
    cin >> a >> x >> b >> y >> t;
    cout << a + 21*(t <= 30 ? 0 : x*(t-30)) << ' ';
    cout << b + 21*(t <= 45 ? 0 : y*(t-45));
    return 0;
}
