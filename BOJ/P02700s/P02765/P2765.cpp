#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld a, b, c, d;

int main()
{
    onlycc;
    for(int i = 1; ; i++)
    {
        cin >> a >> b >> c;
        if(!b) break;
        cout.precision(2);
        cout << fixed << "Trip #" << i << ": " << (d = a / 5280 / 12 * b * M_PI) << ' ' << d/c*3600 << '\n';
    }

    return 0;
}
