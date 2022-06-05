#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll l, r;

int main()
{
    onlycc;
    cin >> l >> r;
    if(l == r && r == 0) cout << "Not a moose";
    else if(l == r) cout << "Even " << l*2;
    else if(l != r) cout << "Odd " << max(l, r)*2;

    return 0;
}
