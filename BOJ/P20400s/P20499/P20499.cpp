#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a[3], cnt;
string s, temp;

int main()
{
    onlycc;
    cin >> s;

    stringstream ss(s);
    while(getline(ss, temp, '/')) a[cnt++] = stoi(temp);
    if(a[0] + a[2] < a[1] || a[1] == 0) cout << "hasu";
    else cout << "gosu";
    return 0;
}
