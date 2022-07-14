#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tc, w, k;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> w >> k;
        cout << w*k/2 << '\n';
    }

    return 0;
}
