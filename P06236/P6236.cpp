#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, money[100000];

int main()
{
    onlycc;
    cin >> n >> m;
    int low = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> money[i];
        low = max(low, money[i]);
    }

    int high = 1000000000;
    while(low <= high)
    {
        int mid = (low+high) / 2;

        ll cnt = 1, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum + money[i] > mid)
            {
                sum = 0;
                cnt++;
            }

            sum += money[i];
        }

        if(cnt > m) low = mid+1;
        else high = mid-1;
    }

    cout << low;

    return 0;
}
