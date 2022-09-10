#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll w1, h1, w2, h2;

int main()
{
    onlycc;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << 4 + (h1+h2)*2 + max(w1, w2)*2;

    return 0;
}
