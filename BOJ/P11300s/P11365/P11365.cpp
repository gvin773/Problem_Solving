#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main()
{
    onlycc;
    while(1)
    {
        getline(cin, s);
        if(s == "END") break;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }

    return 0;
}
