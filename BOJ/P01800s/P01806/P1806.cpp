#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, s, a[100000], sum, lo, hi, len = 987654321;

int main()
{
    onlycc;
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    while(1)
    {
        if(sum > s) sum -= a[lo++];
        else if(hi == n) break;
        else sum += a[hi++];
        if(sum >= s) len = min(len, hi-lo);
    }
    cout << (len == 987654321 ? 0 : len);

    return 0;
}
