#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, fail[1000001], ans;
string t, p;
char x;

ll gcd(ll a, ll b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        t.push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    if(t == p) ans--;
    t += t;

    for(int i = 1, j = 0; i < p.size(); i++)
    {
        while(j > 0 && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }

    for(int i = 0, j = 0; i < t.size(); i++)
    {
        while(j > 0 && t[i] != p[j]) j = fail[j-1];
        if(t[i] == p[j])
        {
            if(j == p.size()-1)
            {
                ans++;
                j = fail[j];
            }
            else j++;
        }
    }

    ll R = gcd(ans, n);
    cout << ans/R << '/' << n/R;

    return 0;
}
