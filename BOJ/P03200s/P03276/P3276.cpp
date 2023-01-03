#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x = 1, y = 1;

int main()
{
    onlycc;
    cin >> n;
    while(x*y < n)
    {
        if(x < y) x++;
        else y++;
    }
    cout << x << ' ' << y;

    return 0;
}
