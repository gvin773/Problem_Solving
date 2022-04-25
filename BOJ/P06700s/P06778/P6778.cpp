#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    if(a>=3&&b<=4) cout << "TroyMartian\n";
    if(a<=6&&b>=2) cout << "VladSaturnian\n";
    if(a<=2&&b<=3) cout << "GraemeMercurian\n";

    return 0;
}
