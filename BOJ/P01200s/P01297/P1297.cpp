#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int d, h, w;
double x;

int main()
{
    onlycc;
    cin >> d >> h >> w;
    x = sqrt(h*h+w*w);
    cout << ll(d*h/x) << ' ' << ll(d*w/x);

    return 0;
}
