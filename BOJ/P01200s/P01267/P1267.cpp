#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x, sa, sb;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> x;
        sa += (x/30+1)*10, sb += (x/60+1)*15;
    }
    cout << (sa == sb ? "Y M " : sa < sb ? "Y " : "M ");
    cout << (sa < sb ? sa : sb);

    return 0;
}
