#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a, b;
vector<ll> A, B;

int main()
{
    onlycc;
    cin >> a >> b;

    A.push_back(a);
    B.push_back(b);
    for(ll i = 2; i*i <= a; i++)
    {
        while(a%i == 0)
        {
            a /= i;
            A.push_back(a);
        }
    }
    for(ll i = 2; i*i <= b; i++)
    {
        while(b%i == 0)
        {
            b /= i;
            B.push_back(b);
        }
    }
    A.push_back(1);
    B.push_back(1);

    for(auto x : A)
    {
        for(auto y : B)
        {
            if(x == y)
            {
                cout << x;
                return 0;
            }
        }
    }

    return 0;
}
