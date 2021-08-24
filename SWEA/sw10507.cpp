#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int t, n, p, pSum[1000001], day, last;
bool check[1000001];

int main()
{
    onlycc;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        last = 0;
        memset(check, 0, sizeof(check));
        memset(pSum, 0, sizeof(pSum));
        cin >> n >> p;
        for(int j = 0; j < n; j++)
        {
            cin >> day;
            last = max(last, day);
            check[day] = true;
        }

        pSum[0] = check[0];
        for(int j = 1; j <= 1000000; j++) pSum[j] = pSum[j-1] + check[j];

        int ans = 0;
        for(int left = 0; left <= last; left++)
        {
            int lo = left, hi = left+n+p-1;
            if(hi > 1000000) hi = 1000000;

            while(lo <= hi)
            {
                int mid = (lo+hi) / 2, sum;
                if(left != 0) sum = pSum[mid] - pSum[left-1];
                else sum = pSum[mid];

                if(sum+p >= mid-left+1)
                {
                    lo = mid+1;
                    ans = max(ans, mid-left+1);
                }
                else hi = mid-1;
            }
        }

        cout << '#' << i << ' ' << ans << '\n';
    }

    return 0;
}
