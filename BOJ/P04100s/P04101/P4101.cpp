#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

int main()
{
    onlycc;
    while(1)
    {
        cin >> a >> b;
        if(a == b && b == 0) break;
        if(a > b) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
