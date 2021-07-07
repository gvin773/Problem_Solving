#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, m, pSum[1000001], cnt[1001], ans;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> pSum[i];
        (pSum[i] += (pSum[i-1]%m)) %= m;
        cnt[pSum[i]]++;
    }

    ans += cnt[0];
    for(int i = 0; i < m; i++)
        ans += cnt[i]*(cnt[i]-1)/2;

    cout << ans;

    return 0;
}
