#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n, m, c, ans = 46464646;
bool b[15];

int main()
{
    onlycc;
    cin >> n >> m;
    if(m != 0) for(int i = 0; i < m; i++)
    {
        cin >> c;
        b[c] = true;
    }

    for(int i = 0; i <= 1000000; i++)
    {
        bool flag = false;
        string s = to_string(i);
        for(int j = 0; j < s.size(); j++)
        {
            if(b[s[j]-'0'] == true)
            {
                flag = true;
                break;
            }
        }
        if(flag && i != 100) continue;

        if(i == 100) ans = min(ans, abs(n-i));
        else ans = min(ans, (int)s.size() + abs(n - i));
    }

    cout << ans;

    return 0;
}
