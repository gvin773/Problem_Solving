#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, n, a, b;

int main()
{
    onlycc;
    cin >> x >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x -= (a*b);
    }
    if(x) cout << "No";
    else cout << "Yes";

    return 0;
}
