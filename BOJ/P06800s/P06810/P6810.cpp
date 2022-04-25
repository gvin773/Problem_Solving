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
    cout << "The 1-3-sum is " << 91+a+3*b+c;

    return 0;
}
