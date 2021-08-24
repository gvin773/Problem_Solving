#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

int t, n, a, b;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        vector<pair<int, int>> v, ans;
        set<int> s;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back({a, b});
            s.insert(b);
        }

        int now;
        for(auto i = v.begin(); i != v.end(); i++)
        {
            if(s.find(i->first) == s.end())
            {
                ans.push_back(*i);
                now = i->second;
                v.erase(i);
                break;
            }
        }

        while(!v.empty())
        {
            for(auto i = v.begin(); i != v.end(); i++)
            {
                if(i->first == now)
                {
                    ans.push_back(*i);
                    now = i->second;
                    v.erase(i);
                    break;
                }
            }
        }

        cout << '#' << tc << ' ';
        for(auto i : ans) cout << i.first << ' ' << i.second << ' ';
        cout << '\n';
    }

    return 0;
}
