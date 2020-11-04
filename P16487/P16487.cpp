#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a, b, c, m;

int main()
{
    onlycc;
    cin >> a >> b >> c >> m;
    ld d = (a*a*(b-m)+c*c*m)/(ld)b+m*m-m*b;
    cout << fixed;
    cout.precision(10);
    cout << d;

    return 0;
}
