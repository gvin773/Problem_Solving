#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c, d;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    cout << ((d = a+b-2*c) >= 0 ? d : a+b);

    return 0;
}
