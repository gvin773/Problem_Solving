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
    if(a == b && b == c) cout << "*";
    else if(a != b && b == c) cout << "A";
    else if(b != c && c == a) cout << "B";
    else cout << "C";

    return 0;
}
