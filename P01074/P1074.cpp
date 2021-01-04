#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, r, c, num, ans;

ll check(ll s, ll x, ll y, ll sum)
{
    if(s == 2) return sum + ans;

    if(x <= s/2 && y <= s/2) return check(s/2, x, y, sum);
    else if(x <= s/2 && y > s/2) return check(s/2, x, y-s/2, sum+s/2*s/2);
    else if(x > s/2 && y <= s/2) return check(s/2, x-s/2, y, sum+s/2*s);
    else if(x > s/2 && y > s/2) return check(s/2, x-s/2, y-s/2, sum+s/2*s/2*3);
}

int main()
{
    onlycc;
    cin >> n >> r >> c;

    if(r%2 == 0 && c%2 == 0) ans = 1;
    else if(r%2 == 0 && c%2 == 1) ans = 2;
    else if(r%2 == 1 && c%2 == 0) ans = 3;
    else if(r%2 == 1 && c%2 == 1) ans = 4;

    cout << check(pow((ll)2,n), r+1, c+1, 0)-1;

    return 0;
}
