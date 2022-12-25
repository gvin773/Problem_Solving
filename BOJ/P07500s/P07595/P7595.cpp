#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n;

int main()
{
    onlycc;
    while(1)
    {
        cin >> n;
        if(!n) break;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++) cout << '*';
            cout << '\n';
        }
    }

    return 0;
}
