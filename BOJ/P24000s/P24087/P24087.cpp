#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll s, a, b;

int main()
{
    onlycc;
    cin >> s >> a >> b;
    cout << 250 + (s-a >= 0 ? ((s-a)/b + !!((s-a)%b))*100 : 0);

    return 0;
}
