#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n;

bool f(ll x)
{
    vector<ll> v;
    ll sum = 0;
    for(int i = 1; i < x; i++)
    {
        if(!(x%i))
        {
            v.push_back(i);
            sum += i;
        }
    }
    if(sum <= x) return true;
    return false;
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        vector<ll> v;
        ll sum = 0;
        for(int i = 1; i < n; i++)
        {
            if(!(n%i))
            {
                v.push_back(i);
                sum += i;
            }
        }
        if(sum <= n)
        {
            cout << "BOJ 2022\n";
            continue;
        }

        for(auto a : v)
        {
            if(a == n) continue;
            if(!f(a))
            {
                cout << "BOJ 2022\n";
                goto xy;
            }
        }
        cout << "Good Bye\n";
        xy:;
    }

    return 0;
}
