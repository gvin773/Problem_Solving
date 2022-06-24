#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, l, r;

int main()
{
    onlycc;
    cin >> a >> b;

    while(!(a == 1 && b == 1))
    {
        if(a > b)
        {
            if(b != 1)
            {
                l += a/b;
                a %= b;
            }
            else
            {
                l += a-1;
                a = 1;
            }
        }
        else
        {
            if(a != 1)
            {
                r += b/a;
                b %= a;
            }
            else
            {
                r += b-1;
                b = 1;
            }
        }
    }
    cout << l << ' ' << r;

    return 0;
}
