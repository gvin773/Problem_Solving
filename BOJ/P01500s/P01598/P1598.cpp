#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, s;

int main()
{
    onlycc;
    cin >> a >> b;
    s = abs((a%4==0?4:a%4) - (b%4==0?4:b%4));
    a--, b--;
    cout << s + abs(a/4 - b/4);

    return 0;
}
