#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll t, n;

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;

        ll cnt = 0, state = 0;
        while(state != (1<<10) - 1)
        {
            cnt++;
            ll N = n*cnt;

            while(N)
            {
                int x = N % 10;
                state |= (1<<x);
                N /= 10;
            }
        }

        cout << "#" << i+1 << ' ' << n*cnt << '\n';
    }

    return 0;
}
