#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll x[4], y[4], l;

int main()
{
    onlycc;
    for(int i = 0; i < 2; i++) cin >> x[2*i] >> y[2*i] >> x[2*i+1] >> y[2*i+1];
    sort(x, x+4);
    sort(y, y+4);
    cout << (l = max(x[3]-x[0], y[3]-y[0]))*l;

    return 0;
}
