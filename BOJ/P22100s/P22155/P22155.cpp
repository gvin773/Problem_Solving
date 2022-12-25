#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, i, f;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> i >> f;
        if((i <= 1 && f <= 2) || (i <= 2 && f <= 1)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
