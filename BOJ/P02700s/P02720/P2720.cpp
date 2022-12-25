#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, c;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> c;
        cout << c/25 << ' '; c %= 25;
        cout << c/10 << ' '; c %= 10;
        cout << c/5 << ' '; c %= 5;
        cout << c << '\n';
    }

    return 0;
}
