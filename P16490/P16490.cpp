#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a, t;

int main()
{
    onlycc;
    cin >> a >> t;
    cout << a*a-t*t;

    return 0;
}
