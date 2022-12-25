#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll fail[1000000];
string t, p;
vector<ll> ans;

int main()
{
    onlycc;
    getline(cin, t);
    getline(cin, p);

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
                ans.push_back(i-p.size()+1 + 1);
                j = fail[j];
            }
            else j++;
        }
    }

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';

    return 0;
}
