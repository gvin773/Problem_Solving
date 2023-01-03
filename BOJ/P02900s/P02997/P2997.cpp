#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a[3];

int main()
{
    onlycc;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[1]-a[0] == a[2]-a[1]) cout << a[2]+a[1]-a[0];
    else if(a[1]-a[0] > a[2]-a[1]) cout << a[0]+a[2]-a[1];
    else cout << a[1]+a[1]-a[0];

    return 0;
}
