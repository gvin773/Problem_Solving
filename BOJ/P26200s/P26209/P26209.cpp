#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, y;

int main()
{
    onlycc;
    for(int i = 0; i < 8; i++)
    {
        cin >> x;
        if(x&8) y = 1;
    }
    cout << (y ? "F" : "S");

    return 0;
}
