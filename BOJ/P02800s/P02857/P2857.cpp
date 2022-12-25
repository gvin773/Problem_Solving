#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll x;
string s;

int main()
{
    onlycc;
    for(int i = 1; i <= 5; i++)
    {
        cin >> s;
        if(s.find("FBI") != string::npos) cout << (x = i) << ' ';
    }
    if(!x) cout << "HE GOT AWAY!";

    return 0;
}
