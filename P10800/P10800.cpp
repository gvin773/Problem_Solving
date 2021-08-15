#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef long long ll;

int n, pSum[200002];
pair<pair<int, int>, int> p[200002]; //<<size, index>, order>
map<int, int> m;
pair<int, int> ans[200002]; //<index, ans>

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].first.second >> p[i].first.first;
        p[i].second = i;
    }

    sort(p, p+n+1);
    for(int i = 1; i <= n; i++) pSum[i] = pSum[i-1] + p[i].first.first;

    ll Plus = 0;
    for(int i = 1; i <= n; i++)
    {
        Plus += p[i].first.first;

        ll temp = 0;
        if(m.find(p[i].first.second) != m.end())
        {
            temp = m[p[i].first.second];
            if(p[i].first.first != p[i+1].first.first || p[i].first.second != p[i+1].first.second)
            {
                m[p[i].first.second] += Plus;
                Plus = 0;
            }
        }
        else if(p[i].first.first != p[i+1].first.first || p[i].first.second != p[i+1].first.second)
        {
            m[p[i].first.second] = Plus;
            Plus = 0;
        }

        int j = i;
        while(p[j].first.first == p[j-1].first.first) j--;
        ans[i].second = pSum[j-1] - temp;
        ans[i].first = p[i].second;
    }

    sort(ans, ans+n+1);
    for(int i = 1; i <= n; i++) cout << ans[i].second << '\n';

    return 0;
}
