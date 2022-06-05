#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a, b, c;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    cout << 2*min(min(b+2*c, a+c), 2*a+b);

    return 0;
}
