#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, k, x;

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        if(n%i == 0)
        {
            x++;
            if(x == k)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}
