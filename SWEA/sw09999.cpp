#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll t, L, N, s[100000], e[100000], pSum[100000];

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> L >> N;

        cin >> s[0] >> e[0];
        pSum[0] = e[0] - s[0];
        for(int i = 1; i < N; i++)
        {
            cin >> s[i] >> e[i];
            pSum[i] = pSum[i-1] + e[i] - s[i];
        }

        ll ans = 0;
        for(int i = 0; i < N; i++)
        {
            ll left = s[i], right = left+L;
            if(right <= e[i])
            {
                ans = max(ans, L);
                break;
            }

            int lo = 0, hi = N-1;
            while(lo <= hi)
            {
                int mid = (lo+hi) / 2;

                if(right >= e[mid]) lo = mid+1;
                else hi = mid-1;
            }

            ll temp = 0;
            if(i == 0) temp += pSum[hi];
            else temp += pSum[hi] - pSum[i-1];

            if(hi+1 < N)
            {
                ll add = right-s[hi+1];
                if(add > 0) temp += add;
            }

            ans = max(ans, temp);
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
