#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b, c;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    cout << max(a,max(b,c))*3 - (a+b+c);

    return 0;
}
