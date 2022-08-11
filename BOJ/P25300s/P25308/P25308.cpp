#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll a[8], idx[8], ans;

int main()
{
    onlycc;
    for(int i = 0; i < 8; i++) cin >> a[i];
    for(int i = 0; i < 8; i++) idx[i] = i+1;

    do
    {
        for(int i = 0; i < 8; i++)
        {
            int j = (i+1) % 8, k = (i+2) % 8;
            if(sqrt(2) * a[idx[i]-1] * a[idx[k]-1] > a[idx[j]-1] * (a[idx[i]-1] + a[idx[k]-1])) goto xy;
        }
        ans++;
        xy:;
    }while(next_permutation(idx, idx+8));
    cout << ans;

    return 0;
}
