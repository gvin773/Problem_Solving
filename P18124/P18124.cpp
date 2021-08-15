#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

int main()
{
    onlycc;
    cin >> n;
    if(n <= 2) cout << n-1;
    else if(n <= 4) cout << 3;
    else
    {
        ll paper = 4, ans = 3, num = 0;
        while(1)
        {
            if(n <= paper*2)
            {
                if(n & 1) n++;
                ans += n/2;
                break;
            }
            else
            {
                ans += paper;
                paper *= 2;
            }
        }

        cout << ans;
    }

    return 0;
}
