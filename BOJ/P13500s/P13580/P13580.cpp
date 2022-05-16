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
    if(a == b || a == c || b == c) cout << "S";
    else if(b+c == a || c+a == b || a+b == c) cout << "S";
    else cout << "N";

    return 0;
}
