#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, fail[500001];
string a, w, s;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> w >> s;

        vector<ll> v;
        unordered_map<char, char> m;
        for(int i = 0; i < a.size(); i++) m[a[i]] = a[(i+1)%a.size()];
        for(int num = 0; num < a.size(); num++)
        {
            for(int i = 0; i < w.size() && num > 0; i++) w[i] = m[w[i]];

            ll cnt = 0;
            memset(fail, 0, sizeof(fail));
            for(int i = 1, j = 0; i < w.size(); i++)
            {
                while(j > 0 && w[i] != w[j]) j = fail[j-1];
                if(w[i] == w[j]) fail[i] = ++j;
            }

            for(int i = 0, j = 0; i < s.size(); i++)
            {
                while(j > 0 && s[i] != w[j]) j = fail[j-1];
                if(s[i] == w[j])
                {
                    if(j == w.size()-1)
                    {
                        cnt++;
                        j = fail[j];
                    }
                    else j++;
                }
            }

            if(cnt == 1) v.push_back(num);
        }

        if(v.empty())
        {
            cout << "no solution\n";
            continue;
        }
        if(v.size() == 1) cout << "unique: ";
        else cout << "ambiguous: ";
        for(auto x : v) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
