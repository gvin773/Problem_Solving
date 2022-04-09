#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

long double a, b, c;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    cout << 2*a*0.001*0.001*229*324 + 2*b*0.001*0.001*297*420 + c*0.001*0.001*210*297;

    return 0;
}
