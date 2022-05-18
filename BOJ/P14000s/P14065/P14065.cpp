#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

long double x;

int main()
{
    onlycc;
    cin >> x;
    cout.precision(10);
    cout << 3.785411784 / (x * 1609.344 * 0.00001);

    return 0;
}
