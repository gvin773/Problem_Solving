#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, a, b, c;

int main()
{
    onlycc;
    cin >> n;
    cout << "Gnomes:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if((a < b && b < c) || (a > b && b > c)) cout << "Ordered\n";
        else cout << "Unordered\n";
    }

    return 0;
}
