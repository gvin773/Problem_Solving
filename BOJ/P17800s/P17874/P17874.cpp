#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, h, v;

int main()
{
    onlycc;
    cin >> n >> h >> v;
    cout << 4*max(max(h*v, (n-h)*(n-v)), max(h*(n-v), (n-h)*v));

    return 0;
}
