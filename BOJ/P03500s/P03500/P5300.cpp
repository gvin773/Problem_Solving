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
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << i+1 << ' ';
        if(i+1 == n)
        {
            cout << "Go!";
            break;
        }
        if((i+1)%6 == 0) cout << "Go! ";
    }
    return 0;
}
