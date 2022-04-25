#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    if(b < a) swap(a, b);
    if(!(a&1) || !(b&1)) cout << 0;
    else cout << a;

    return 0;
}
