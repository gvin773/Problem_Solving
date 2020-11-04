#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

ll r1, r2, r3;
ld r;

int main()
{
    onlycc;
    cin >> r1 >> r2 >> r3;
    r = (r1*r2*r3)/(ld)(r1*r2+r2*r3+r3*r1);
    cout << fixed;
    cout.precision(10);
    cout << r;

    return 0;
}
