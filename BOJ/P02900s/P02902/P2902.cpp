#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

string s;
vector<char> ans;

int main()
{
    onlycc;
    cin >> s;
    for(auto x : s) if('A' <= x && x <= 'Z') ans.push_back(x);
    for(auto x : ans) cout << x;

    return 0;
}
