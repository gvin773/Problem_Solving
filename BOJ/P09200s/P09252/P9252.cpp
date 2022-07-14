#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s1, s2;
int dp[1010][1010], c[1010][1010];

int LCS(int a, int b)
{
    if(dp[a][b] != -1) return dp[a][b];
    if(a == s1.size() || b == s2.size()) return 0;

    int &ret = dp[a][b];

    int t1 = LCS(a+1, b), t2 = LCS(a, b+1);
    if(t1 > t2)
    {
        ret = t1;
        c[a][b] = 1;
    }
    else
    {
        ret = t2;
        c[a][b] = 2;
    }
    if(s1[a] == s2[b])
    {
        int t3 = LCS(a+1, b+1) + 1;
        if(ret < t3)
        {
            ret = t3;
            c[a][b] = 3;
        }
    }

    return ret;
}

void track(int a, int b)
{
    if(a == s1.size() || b == s2.size()) return;

    if(c[a][b] == 1) track(a+1, b);
    else if(c[a][b] == 2) track(a, b+1);
    else
    {
        cout << s1[a];
        track(a+1, b+1);
    }
}

int main()
{
    onlycc;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout << LCS(0, 0) << '\n';
    track(0, 0);

    return 0;
}
