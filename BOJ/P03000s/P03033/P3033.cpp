#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll l;
string s;
const int MOD = 111111;

ll calc(ll x)
{
    if(x >= 0) return x % MOD;
    return ((-x/MOD+1)*MOD+x) % MOD;
}

int main()
{
    onlycc;
    cin >> l >> s;

    int lo = 0, hi = l;
    while(lo+1 < hi)
    {
        int mid = (lo+hi) / 2;

        ll H = 0, power = 1;
        vector<ll> v[MOD];
        bool flag = false;

        for(int i = 0; i <= l-mid; i++)
        {
            if(i == 0)
            {
                for(int j = 0; j < mid; j++)
                {
                    H = calc(H + s[mid-1-j]*power);
                    if(j < mid-1) power = calc(power*2);
                }
            }
            else H = calc(2*(H-s[i-1]*power) + s[i+mid-1]);

            if(!v[H].empty())
            {
                for(auto x : v[H])
                {
                    flag = true;
                    for(int j = 0; j < mid; j++)
                    {
                        if(s[i+j] != s[x+j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) goto xy;
                }
            }
            v[H].push_back(i);
        }

        xy:;
        if(flag) lo = mid;
        else hi = mid;
    }
    cout << lo;

    return 0;
}
