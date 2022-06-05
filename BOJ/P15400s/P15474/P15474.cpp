#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, a, b, c, d, e, f;

int main()
{
    onlycc;
    cin >> n >> a >> b >> c >> d;
    e = b*(n/a+!!(n%a));
    f = d*(n/c+!!(n%c));
    cout << (e < f ? e : f);
    return 0;
}
