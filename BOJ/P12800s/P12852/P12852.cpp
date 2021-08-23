#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

int dp[1000001], n;
vector<int> v;

int f(int x)
{
    if(dp[x] != -1) return dp[x];
    int &ans = dp[x] = x;

    if(x%3 == 0) ans = min(ans, 1+f(x/3));
    if(x%2 == 0) ans = min(ans, 1+f(x/2));
    if(x > 1) ans = min(ans, 1+f(x-1));

    return ans;
}

void seq()
{
    int x1, x2, x3, m;
    while(n != 1)
    {
        x1 = 46464646, x2 = 46464646, x3 = 46464646;
        if(n%3 == 0) x1 = f(n/3);
        if(n%2 == 0) x2 = f(n/2);
        if(n > 1) x3 = f(n-1);

        m = min(x1, min(x2, x3));
        if(m == x1)
        {
            v.push_back(n/3);
            n /= 3;
        }
        else if(m == x2)
        {
            v.push_back(n/2);
            n /= 2;
        }
        else if(m == x3)
        {
            v.push_back(n-1);
            n -= 1;
        }
    }
}

int main()
{
    onlycc;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    v.push_back(n);
    cout << f(n) << '\n';
    seq();
    for(int i : v) cout << i << ' ';

    return 0;
}
