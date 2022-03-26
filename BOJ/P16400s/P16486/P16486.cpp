#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

long double d1, d2;

int main()
{
    onlycc;
    cin >> d1 >> d2;
    cout.precision(10);
    cout << 2*d1+2*3.141592*d2;

    return 0;
}
