#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, a, b, c, d, e, f, im1, i1, i2, i3;

int main()
{
    onlycc;
    cin >> n >> a >> b >> c >> d >> e >> f;

    i1 = min(a < b ? a : b, c < d ? c : d);
    i1 = min(i1, e < f ? e : f);
    im1 = max(a > b ? a : b, c > d ? c : d);
    im1 = max(im1, e > f ? e : f);

    i2 = (a+b < a+c ? a+b : a+c);
    i2 = min(i2, a+d < a+e ? a+d : a+e);
    i2 = min(i2, b+c < b+d ? b+c : b+d);
    i2 = min(i2, b+f);
    i2 = min(i2, c+e < c+f ? c+e : c+f);
    i2 = min(i2, d+e < d+f ? d+e : d+f);
    i2 = min(i2, e+f);

    i3 = (a+b+c < a+b+d ? a+b+c : a+b+d);
    i3 = min(i3, a+c+e < a+d+e ? a+c+e : a+d+e);
    i3 = min(i3, b+c+f < b+d+f ? b+c+f : b+d+f);
    i3 = min(i3, c+e+f < d+e+f ? c+e+f : d+e+f);

    if(n == 1) cout << a+b+c+d+e+f-im1;
    else cout << i3*4 + i2*(8*(n-2)+4) + i1*(5*(n-2)*(n-2) + 4*(n-2));

    return 0;
}
