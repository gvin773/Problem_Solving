#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

ll n, d;

int main()
{
    onlycc;
    cin >> n >> d;
    ld qy = (n-2*d)/2.0;
    cout << fixed;
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << qy;

    return 0;
}
