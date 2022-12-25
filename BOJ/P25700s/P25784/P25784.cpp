#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll i = 3, a[3];

int main()
{
    onlycc;
    while(i--) cin >> a[i];
    sort(a, a+3);
    if(a[0]+a[1] == a[2]) cout << 1;
    else if(a[0]*a[1] == a[2]) cout << 2;
    else cout << 3;

    return 0;
}
