#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll R, r, d2;

int main()
{
    onlycc;
    cin >> R >> r;
    d2 = R*R - 2*R*r;
    cout << d2;

    return 0;
}
