#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, c, e, x, y, z;

int main()
{
    onlycc;
    cin >> a >> c >> e >> x >> y >> z;
    if((ld)y < c/(ld)2) cout << 'E';
    else if(y < c) cout << 'D';
    else
    {
        if((ld)x < a/(ld)2) cout << 'C';
        else if(x < a) cout << 'B';
        else cout << 'A';
    }

    return 0;
}
