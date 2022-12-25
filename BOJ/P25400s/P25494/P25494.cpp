#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, a, b, c, ans;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b >> c;
        for(int i = 1; i <= a; i++)
        {
            for(int j = 1; j <= b; j++)
            {
                for(int k = 1; k <= c; k++)
                {
                    if(i%j == j%k && j%k == k%i) ans++;
                }
            }
        }
        cout << ans << '\n';
        ans = 0;
    }

    return 0;
}
