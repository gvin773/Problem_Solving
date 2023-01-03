#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, a, b, c;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b >> c;
        cout << "Data set: " << a << ' ' << b << ' ' << c << '\n';
        while(c--)
        {
            if(a > b) a /= 2;
            else b /= 2;
        }
        if(b > a) swap(a, b);
        cout << a << ' ' << b << "\n\n";
    }

    return 0;
}
