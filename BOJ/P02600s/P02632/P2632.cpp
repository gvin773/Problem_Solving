#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll n, m, Size, a[1000], b[1000], ans;
vector<ll> p1, p2;

int main()
{
    onlycc;
    cin >> Size >> m >> n;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll all = 0;
    for(int i = 0; i < m; i++)
    {
        ll sum = 0, cnt = i, flag = 0;
        while(sum <= Size && flag < m)
        {
            flag++;
            if(flag == m && all == 0) all = 1;
            else if(flag == m && all == 1) continue;

            if(cnt == m) cnt = 0;
            sum += a[cnt++];
            if(sum <= Size) p1.push_back(sum);
        }
    }

    all = 0;
    for(int i = 0; i < n; i++)
    {
        ll sum = 0, cnt = i, flag = 0;
        while(sum <= Size && flag < n)
        {
            flag++;
            if(flag == n && all == 0) all = 1;
            else if(flag == n && all == 1) continue;

            if(cnt == n) cnt = 0;
            sum += b[cnt++];
            if(sum <= Size) p2.push_back(sum);
        }
    }

    for(ll i : p1) if(i == Size) ans++;
    for(ll i : p2) if(i == Size) ans++;

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    for(int i = 0; i < p1.size() && p1[i] <= Size; i++)
    {
        int L = lower_bound(p2.begin(), p2.end(), Size-p1[i]) - p2.begin();
        int R = upper_bound(p2.begin(), p2.end(), Size-p1[i]) - p2.begin();
        ans += R-L;
    }

    cout << ans;

    return 0;
}
