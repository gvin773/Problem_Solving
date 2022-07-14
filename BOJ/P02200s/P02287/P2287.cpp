#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll k, n, a, x;
set<ll> dp[9];

void f(int z)
{
    for(int i = 1; i < z; i++)
    {
        for(auto n1 : dp[i]) for(auto n2 : dp[z-i])
        {
            dp[z].insert(n1+n2);
            dp[z].insert(n1-n2);
            dp[z].insert(n1*n2);
            if(n2 != 0) dp[z].insert(n1/n2);
        }
    }
}

int main()
{
    onlycc;
    cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;

        int temp = k;
        for(int j = 2; j <= 8; j++)
        {
            temp *= 10;
            temp += k;
            dp[j].insert(temp);
        }
        dp[1].insert(k);

        for(x = 1; x <= 8; x++)
        {
            f(x);
            if(dp[x].find(a) != dp[x].end()) break;
        }
        if(x == 9) cout << "NO\n";
        else cout << x << '\n';
    }

    return 0;
}
