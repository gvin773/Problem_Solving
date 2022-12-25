#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a[5], s;

int main()
{
    onlycc;
    for(int i = 0; i < 5; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    sort(a, a+5);
    cout << s/5 << '\n' << a[2];

    return 0;
}
