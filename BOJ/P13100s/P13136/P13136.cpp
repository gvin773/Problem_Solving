#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll r, c, n;

int main()
{
    onlycc;
    cin >> r >> c >> n;
    cout << (r/n+!!(r%n)) * (c/n+!!(c%n));

    return 0;
}
