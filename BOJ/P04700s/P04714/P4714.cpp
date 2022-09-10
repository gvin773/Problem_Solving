#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld x;

int main()
{
    onlycc;
    while(1)
    {
        cin >> x;
        if(x < 0) break;
        cout.precision(2);
        cout << fixed << "Objects weighing " << x << " on Earth will weigh ";
        cout << 0.167*x << " on the moon.\n";
    }

    return 0;
}
