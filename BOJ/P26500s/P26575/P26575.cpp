#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld n, d, f, p;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> d >> f >> p;
        cout.precision(2);
        cout << fixed << '$' << d*f*p << '\n';
    }

    return 0;
}
