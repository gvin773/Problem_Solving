#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, d, e, f;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d >> e >> f;
    cout << d-a - (50*b+c > 50*e+f) << '\n' << d-a+1 << '\n' << d-a;

    return 0;
}
