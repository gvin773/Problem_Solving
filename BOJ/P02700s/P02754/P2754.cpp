#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define R (c[1]=='+'?0.3:(c[1]=='-'?-0.3:0.0))
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string c;

int main()
{
    onlycc;
    cin >> c;
    cout << fixed;
    cout.precision(1);
    if(c[0] == 'A') cout << 4.0 + R;
    else if(c[0] == 'B') cout << 3.0 + R;
    else if(c[0] == 'C') cout << 2.0 + R;
    else if(c[0] == 'D') cout << 1.0 + R;
    else cout << 0.0;

    return 0;
}
