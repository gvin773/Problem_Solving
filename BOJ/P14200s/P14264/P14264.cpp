#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int L;

int main()
{
    onlycc;
    cin >> L;
    cout.precision(10);
    cout << sqrt(3) / 4 * (long double)L * (long double)L;

    return 0;
}
