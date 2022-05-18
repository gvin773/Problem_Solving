#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b, c, d, e, cnt;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> e;
    if(a < 0) cnt -= c*a;
    if(a <= 0) cnt += d;
    cnt += e*(b - max(a, 0));

    cout << cnt;

    return 0;
}
