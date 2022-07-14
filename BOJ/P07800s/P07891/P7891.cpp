#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tc, x, y;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> x >> y;
        cout << x+y << '\n';
    }

    return 0;
}
