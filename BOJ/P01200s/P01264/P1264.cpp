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
        if(s == "#") break;

        ll cnt = 0;
        for(auto i : s) if(i=='a'||i=='A'||i=='e'||i=='E'||i=='i'||i=='I'||i=='o'||i=='O'||i=='u'||i=='U') cnt++;
        cout << cnt << '\n';
    }

    return 0;
}
