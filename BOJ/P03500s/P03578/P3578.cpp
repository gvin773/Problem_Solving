#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int h;

int main()
{
    onlycc;
    cin >> h;
    if(h == 0) cout << 1;
    else if(h == 1) cout << 0;
    else
    {
        if(h&1) cout << 4;
        for(int i = 0; i < h/2; i++) cout << 8;
    }

    return 0;
}
