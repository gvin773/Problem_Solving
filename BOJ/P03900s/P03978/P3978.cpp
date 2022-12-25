#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, n, m, k;
string s;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> k >> s;
        if(k == 1)
        {
            while(m--) cout << 'a';
            cout << '\n';
            continue;
        }

        vector<char> v;
        for(int len = 1, MOD = k; len <= n; len++, MOD *= k)
        {
            ll H = 0;
            bool visited[100000] = {};

            for(int i = 0; i < len-1; i++) H = (k*H + s[i]-'a') % MOD;
            for(int i = len-1; i < n; i++)
            {
                H = (k*H + s[i]-'a') % MOD;
                visited[H] = true;
            }

            for(int i = 0; i < MOD; i++)
            {
                if(!visited[i])
                {
                    for(int j = 0; j < len; j++)
                    {
                        v.push_back('a' + i%k);
                        i /= k;
                    }
                    goto fin;
                }
            }
        }
        fin:;
        for(int i = v.size()-1; i >= 0; i--) cout << v[i];
        cout << '\n';
    }

    return 0;
}
