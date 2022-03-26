#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int getx(int A, int P)
{
    return A*P;
}

int gety(int B, int C, int D, int P)
{
    return (P <= C) ? B : B + (P-C)*D;
}

int a, b, c, d, p;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> p;
    a = getx(a, p);
    b = gety(b, c, d, p);
    cout << (a < b ? a : b);

    return 0;
}
