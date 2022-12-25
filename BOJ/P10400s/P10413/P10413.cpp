#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int MAX = 100000;

ll tc, sa[MAX], group[MAX], lcp[MAX], d, ans;
string s;

bool cmp(ll a, ll b)
{
    if(group[a] != group[b]) return group[a] < group[b];
    a += d, b += d;
    return (a < s.size() && b < s.size()) ? (group[a] < group[b]) : (a > b);
}

void makeSA()
{
    for(int i = 0; i < s.size(); i++)
    {
        sa[i] = i;
        group[i] = s[i];
    }

    for(d = 1; ; d*=2)
    {
        sort(sa, sa+s.size(), cmp);

        ll ngroup[MAX] = {};
        for(int i = 0; i < s.size()-1; i++) ngroup[i+1] = ngroup[i] + cmp(sa[i], sa[i+1]);
        for(int i = 0; i < s.size(); i++) group[sa[i]] = ngroup[i];

        if(ngroup[s.size()-1] == s.size()-1) break;
    }
}

void makeLCP() //LCP[x] : between SA[x] and SA[x+1]
{
    for(int i = 0, k = 0; i < s.size(); i++, k = max(k-1, 0))
    {
        if(group[i] == s.size()-1) continue;

        for(int j = sa[group[i]+1]; s[i+k] == s[j+k]; k++);
        lcp[group[i]] = k;
    }
}

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> s;

        makeSA();
        makeLCP();

        ans = lcp[0];
        for(int i = 0; i < s.size()-1; i++) ans += (lcp[i+1] - lcp[i] > 0 ? lcp[i+1] - lcp[i] : 0);

        cout << ans << '\n';
    }

    return 0;
}
