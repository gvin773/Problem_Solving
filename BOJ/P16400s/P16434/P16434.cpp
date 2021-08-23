#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll h_atk, n, t[123456], a[123456], h[123456];
ll h_maxhp, h_curhp;

int main()
{
    onlycc;
    cin >> n >> h_atk;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> a[i] >> h[i];

    ll low = 0, high = 1e18, ret = 0;
    while(low <= high)
    {
        ll atk = h_atk;
        h_maxhp = h_curhp = (low+high) / 2;

        int cnt = 1; //1 success 0 fail
        for(int i = 0; i < n; i++)
        {
            if(t[i] == 1) //monster
            {
                ll monster = h[i]%atk == 0 ? h[i]/atk : h[i]/atk+1;
                ll player = h_curhp%a[i] == 0 ? h_curhp/a[i] : h_curhp/a[i]+1;
                if(player < monster)
                {
                    cnt = 0;
                    break;
                }
                h_curhp -= a[i]*(monster-1);
            }

            else //potion
            {
                atk += a[i];
                h_curhp = min(h_curhp+h[i], h_maxhp);
            }
        }

        if(cnt == 0) low = h_maxhp+1;
        else
        {
            ret = h_maxhp;
            high = h_maxhp-1;
        }
    }

    cout << ret;

    return 0;
}
