#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k;
bool Prime[1001];

int main()
{
    onlycc;
    cin >> n >> k;
    fill(Prime, Prime+n+1, 1);
    for(int i = 2; i <= n; i++)
    {
        if(Prime[i]) k--;
        else continue;
        if(k == 0)
        {
            cout << i;
            break;
        }
        for(int j = i*2; j <= n; j+=i)
        {
            if(Prime[j]) k--;
            if(k == 0)
            {
                cout << j;
                return 0;
            }
            Prime[j] = false;
        }
    }

    return 0;
}
