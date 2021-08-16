#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a, b, d, diff, ans = 1;

int main()
{
    onlycc;
    cin >> a >> b;
    d = a-2, diff = d+1;
    for(int i = 0; i < b; i++)
    {
        ans += diff;
        diff += d;
    }
    cout << ans;
    return 0;
}
