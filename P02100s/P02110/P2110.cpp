#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, x[200000], c;

int main()
{
    onlycc;
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> x[i];

    sort(x, x+n);

    ll low = 0, high = 1000000000, ret = 0;
    while(low <= high)
    {
        ret = 987654321;
        ll mid = (low+high) / 2;

        int cnt = 1, before = 0;
        for(int i = 1; i < n; i++)
        {
            if(x[i] - x[before] >= mid)
            {
                cnt++;
                ret = min(ret, x[i] - x[before]);
                before = i;
            }
        }

        if(n == 1) ret = 0;
        if(low == mid) break;
        if(cnt >= c) low = mid;
        else high = mid;
    }

    cout << ret;

    return 0;
}
