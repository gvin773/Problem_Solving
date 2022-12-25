#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll fail[1000001], L;
string s;

int main()
{
    onlycc;
    cin >> L >> s;
    for(int i = 1, j = 0; i < s.size(); i++)
    {
        while(j > 0 && s[i] != s[j]) j = fail[j-1];
        if(s[i] == s[j]) fail[i] = ++j;
    }
    cout << L - fail[L-1];

    return 0;
}
