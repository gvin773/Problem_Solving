#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, k, rope[10000];

int main()
{
    onlycc;
    cin >> k >> n;
    ll low = 1, high = 0;
    for(int i = 0; i < k; i++)
    {
        cin >> rope[i];
        high = max(high, rope[i]);
    }

    high++;
    while(low+1 < high)
    {
        ll mid = (low+high) / 2;

        int cnt = 0;
        for(int i = 0; i < k; i++)
        {
            cnt += rope[i] / mid;
        }

        if(cnt >= n) low = mid;
        else high = mid;
    }

    cout << low;

    return 0;
}
