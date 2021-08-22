#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a, b, c, x, y;

int main()
{
    onlycc;
    cin >> a >> b >> c >> x >> y;
    ld z = b/(x*y/(ld)((c-x)*(a-y))+1);
    cout << fixed;
    cout.precision(10);
    cout << z;

    return 0;
}
