#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, les[100000];

int main()
{
    onlycc;
    cin >> n >> m;
    int low = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> les[i];
        low = max(low, les[i]);
    }

    int high = 1000000000;
    while(low <= high)
    {
        ll mid = (low+high) / 2;

        ll cnt = 1, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum + les[i] > mid)
            {
                sum = 0;
                cnt++;
            }

            sum += les[i];
        }

        if(cnt > m) low = mid+1;
        else high = mid-1;
    }

    cout << low;

    return 0;
}
