#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t;
string s;

int main()
{
    onlycc;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << s[0] << s[s.size()-1] << '\n';
    }

    return 0;
}
