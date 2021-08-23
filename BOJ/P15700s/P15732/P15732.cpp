#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, k, d;
pair<pair<ll, ll>, ll> rule[10000];

int main()
{
    onlycc;
    cin >> n >> k >> d;
    for(int i = 0; i < k; i++)
        cin >> rule[i].first.first >> rule[i].first.second >> rule[i].second;

    ll low = 1, high = n+1;
    while(low+1 < high)
    {
        ll mid = (low+high) / 2;

        ll num = 0;
        for(int i = 0; i < k; i++)
        {
            if(rule[i].first.first >= mid) continue;
            num += 1 + (min(mid-1, rule[i].first.second)-rule[i].first.first)/rule[i].second;
        }

        if(num < d)
            low = mid;

        else
            high = mid;
    }

    cout << low;

    return 0;
}
