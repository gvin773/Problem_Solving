#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll at(ll x, ll y)
{
    return (x+y)*(x-y);
}

ll a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    cout << at(a, b);

    return 0;
}
