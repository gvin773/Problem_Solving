#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, k;

int main()
{
    onlycc;
    cin >> n >> k;

    ll low = 1, high = 10000000001, ret = 1;
    while(low <= high)
    {
        ll mid = (low+high) / 2;

        ll cnt = 0;
        for(ll i = 1; i <= n; i++)
        {
            cnt += min(mid/i, n);
        }

        if(cnt < k)
            low = mid+1;

        else
        {
            ret = mid;
            high = mid-1;
        }
    }

    cout << ret;

    return 0;
}
