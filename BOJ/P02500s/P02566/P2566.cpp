#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, a, b, c;

int main()
{
    onlycc;
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            cin >> x;
            if(x >= a) a = x, b = i, c = j;
        }
    }
    cout << a << '\n' << b << ' ' << c;

    return 0;
}
