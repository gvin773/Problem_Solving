#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll t, cnt;
string str;

int recursion(const string &s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const string &s){
    return recursion(s, 0, s.size()-1);
}

int main()
{
    onlycc;
    cin >> t;
    while(t--)
    {
        cin >> str;
        cout << isPalindrome(str) << ' ' << cnt << '\n';
        cnt = 0;
    }

    return 0;
}
