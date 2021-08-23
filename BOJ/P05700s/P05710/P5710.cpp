#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b;

ll cal(ll x)
{
    ll ret;
    if(x <= 100) ret = x*2;
    else if(x <= 10000) ret = (200 + (x-100)*3);
    else if(x <= 1000000) ret = (200 + 9900*3 + (x-10000)*5);
    else ret = (200 + 9900*3 + 990000*5 + (x-1000000)*7);
    return ret;
}

int main()
{
    onlycc;
    while(1)
    {
        cin >> a >> b;
        if(a==0 && b==0) break;

        ll L = 0, R = 10e9;
        while(L <= R)
        {
            ll mid = (L+R)/2;
            if(cal(mid) < a) L = mid+1;
            else R = mid-1;
        }

        int E = L;
        R = L/2, L = 0;
        while(L <= R)
        {
            ll mid = (L+R)/2;
            if(cal(E-mid) - cal(mid) > b) L = mid+1;
            else R = mid-1;
        }
        cout << cal(L) << '\n';
    }

    return 0;
}
