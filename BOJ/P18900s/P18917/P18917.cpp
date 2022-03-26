#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll m, a, b, s, x;

int main()
{
    onlycc;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a;

        if(a == 1)
        {
            cin >> b;
            s += b;
            x ^= b;
        }
        else if(a == 2)
        {
            cin >> b;
            s -= b;
            x ^= b;
        }
        else if(a == 3) cout << s << '\n';
        else cout << x << '\n';
    }

    return 0;
}
