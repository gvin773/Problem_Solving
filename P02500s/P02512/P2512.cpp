#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, money[10000], sum;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> money[i];
        sum += money[i];
    }

    cin >> m;
    if(m >= sum)
    {
        int ret = 0;
        for(int i = 0; i < n; i++)
            ret = max(ret, money[i]);

        cout << ret;

        return 0;
    }

    int low = 0, high = 1000000000;
    while(low+1 < high)
    {
        int mid = (low+high) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(money[i] >= mid) sum += mid;
            else sum += money[i];
        }

        if(sum > m)
            high = mid;

        else
            low = mid;
    }

    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(money[i] >= low) ret = max(ret, low);
        else ret = max(ret, money[i]);
    }

    cout << ret;

    return 0;
}
