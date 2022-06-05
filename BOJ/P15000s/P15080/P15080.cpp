#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a[2], b[2], c[2], ans;
char x, y;

int main()
{
    onlycc;
    for(int i = 0; i < 2; i++) cin >> a[i] >> x >> b[i] >> y >> c[i];
    ans = c[1] + b[1]*60 + a[1]*3600 - c[0] - b[0]*60 - a[0]*3600;
    if(ans < 0) ans += 24*3600;
    cout << ans;

    return 0;
}
