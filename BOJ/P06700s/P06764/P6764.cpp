#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a, b, c, d;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d;
    if(a == b && b == c && c == d) cout << "Fish At Constant Depth";
    else if(a < b && b < c && c < d) cout << "Fish Rising";
    else if(a > b && b > c && c > d) cout << "Fish Diving";
    else cout << "No Fish";

    return 0;
}
