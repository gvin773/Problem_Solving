#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, fail[100001], len[500], dp[100001];
string t, p;
bool possible[100001][500];

int main()
{
    onlycc;
    cin >> t >> n;
    for(int tc = 0; tc < n; tc++)
    {
        memset(fail, 0, sizeof(fail));
        cin >> p;
        len[tc] = p.size();

        for(int i = 1, j = 0; i < p.size(); i++)
        {
            while(j > 0 && p[i] != p[j]) j = fail[j-1];
            if(p[i] == p[j]) fail[i] = ++j;
        }

        for(int i = 0, j = 0; i < t.size(); i++)
        {
            while(j > 0 && t[i] != p[j]) j = fail[j-1];
            if(t[i] == p[j])
            {
                if(j == p.size()-1)
                {
                    possible[i-p.size()+1][tc] = true;
                    j = fail[j];
                }
                else j++;
            }
        }
    }

    for(int i = t.size()-1; i >= 0; i--)
    {
        auto &now = dp[i];
        if(i != t.size()-1) now = dp[i+1];
        for(int j = 0; j < n; j++) if(possible[i][j]) now = max(now, dp[i+len[j]] + len[j]);
    }
    cout << dp[0];

    return 0;
}
