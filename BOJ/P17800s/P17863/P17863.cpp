#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string a;

int main()
{
    onlycc;
    cin >> a;
    if(a.substr(0, 3) == "555") cout << "YES";
    else cout << "NO";

    return 0;
}
