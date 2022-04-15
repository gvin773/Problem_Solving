#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int l, a, b, c, d;

int main()
{
    onlycc;
    cin >> l >> a >> b >> c >> d;
    cout << l - max(a/c+!!(a%c), b/d+!!(b%d));

    return 0;
}
