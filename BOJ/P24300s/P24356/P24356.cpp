#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll t1, m1, t2, m2;

int main()
{
    onlycc;
    cin >> t1 >> m1 >> t2 >> m2;
    t1 = t2*60+m2-t1*60-m1;
    cout << (t1 < 0 ? t1+24*60 : t1) << ' ' << (t1 < 0 ? t1+24*60 : t1)/30;

    return 0;
}
