#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

int a, b, c;

ld newton(ld x)
{
    return x-(a*x+b*sin(x)-c)/(a+b*cos(x));
}

int main()
{
    onlycc;
    cin >> a >> b >> c;

    ld x = 1;
    for(int i = 0; i < 50000; i++)
        x = newton(x);

    cout.fixed;
    cout.precision(15);
    cout << x;

    return 0;
}
