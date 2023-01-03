#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x, y;
string a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    x = stoi(a.substr(0, 2))*60*60, y = stoi(b.substr(0, 2))*60*60;
    x += stoi(a.substr(3, 2))*60, y += stoi(b.substr(3, 2))*60;
    x += stoi(a.substr(6, 2)), y += stoi(b.substr(6, 2));
    if(x >= y) y += 24*60*60;
    y -= x;
    if(y/3600 < 10) cout << 0;
    cout << y/3600 << ':';
    y %= 3600;
    if(y/60 < 10) cout << 0;
    cout << y/60 << ':';
    y %= 60;
    if(y < 10) cout << 0;
    cout << y;

    return 0;
}
