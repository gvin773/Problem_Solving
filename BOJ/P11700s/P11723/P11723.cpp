#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int m, x, status;
string str;

int main()
{
    onlycc;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> str;
        if(str != "empty" && str != "all") cin >> x;

        if(str == "add") status |= 1<<x;
        else if(str == "remove") status &= ~(1<<x);
        else if(str == "check")
        {
            if(status & 1<<x) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "toggle") status ^= 1<<x;
        else if(str == "all") status = (1<<21) - 1;
        else if(str == "empty") status = 0;
    }

    return 0;
}
