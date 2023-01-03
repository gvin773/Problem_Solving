#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a[4];

int main()
{
    onlycc;
    for(int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a+4);
    cout << a[0]*a[2];

    return 0;
}
