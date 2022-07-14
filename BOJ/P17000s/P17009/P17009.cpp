#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll a, b, c, d, e, f;
int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> e >> f;
    if(3*a+2*b+c > 3*d+2*e+f) cout << 'A';
    else if(3*a+2*b+c < 3*d+2*e+f) cout << 'B';
    else cout << 'T';

    return 0;
}
