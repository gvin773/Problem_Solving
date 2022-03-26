#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int ax, ay, az, cx, cy, cz;

int main()
{
    onlycc;
    cin >> ax >> ay >> az >> cx >> cy >> cz;
    cout << cx-az << ' ' << cy/ay << ' ' << cz-ax;

    return 0;
}
