#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int e, s, m, a, b, c, ans;

int main()
{
    onlycc;
    cin >> e >> s >> m;
    while(1)
    {
        a++, b++, c++, ans++;
        if(a == 16) a = 1;
        if(b == 29) b = 1;
        if(c == 20) c = 1;

        if(a == e && b == s && c == m)
        {
            cout << ans;
            return 0;
        }
    }

    return 0;
}
