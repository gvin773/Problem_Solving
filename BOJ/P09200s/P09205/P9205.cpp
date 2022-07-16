#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, x[111], y[111], d[111][111];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(int i = 0; i < n+2; i++) for(int j = 0; j < n+2; j++) d[i][j] = 10000000000LL;
        for(int i = 0; i < n+2; i++) cin >> x[i] >> y[i];

        for(int i = 0; i < n+2; i++)
        {
            for(int j = 0; j < n+2; j++)
            {
                if(i == j) continue;
                if(abs(x[i]-x[j]) + abs(y[i]-y[j]) <= 1000)
                {
                    d[i][j] = 1;
                    d[j][i] = 1;
                }
            }
        }

        for(int k = 0; k < n+2; k++)
        {
            for(int i = 0; i < n+2; i++)
            {
                for(int j = 0; j < n+2; j++)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        if(d[0][n+1] == 10000000000LL) cout << "sad\n";
        else cout << "happy\n";
    }

    return 0;
}
