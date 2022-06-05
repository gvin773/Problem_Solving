#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main()
{
    onlycc;
    cin >> s;
    if(s.size() == 4) cout << 20;
    else if(s.size() == 2) cout << s[0] + s[1] - 2*'0';
    else if(s[1] == '0') cout << 10 + s[2] - '0';
    else cout << 10 + s[0] - '0';

    return 0;
}
