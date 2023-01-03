#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[100001], sum;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1, a+n+1);
    cout.precision(10);
    cout << fixed << (a[n-1]*n < sum ? sum/(ld)n : a[n-1]);

    return 0;
}
