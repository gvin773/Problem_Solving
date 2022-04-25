#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b, c, d;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    d = (a*24+b)*60+c - ((11*24+11)*60+11);
    cout << (d < 0 ? -1 : d);

    return 0;
}
