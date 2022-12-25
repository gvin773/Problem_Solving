#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld n, s, k, x;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x) k++;
        else k = 0;
        s += k;
    }
    cout << s;

    return 0;
}
