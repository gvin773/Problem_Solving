#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, ans;
string mbti, s;

int main()
{
    onlycc;
    cin >> mbti >> n;
    while(n--)
    {
        cin >> s;
        if(mbti == s) ans++;
    }
    cout << ans;

    return 0;
}
