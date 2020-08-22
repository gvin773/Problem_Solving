#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, card[100000], cnt[100000] = {1, };

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> card[i];

    sort(card, card+n);
    ll temp = 0, ret = 1;
    for(int i = 1; i < n; i++)
    {
        if(card[i] == card[i-1])
            cnt[i] = cnt[i-1] + 1;

        else
        {
            if(temp < cnt[i-1])
            {
                ret = card[i-1];
                temp = cnt[i-1];
            }
            cnt[i] = 1;
        }
    }

    if(cnt[n-1] > temp)
        ret = card[n-1];

    cout << ret;

    return 0;
}
