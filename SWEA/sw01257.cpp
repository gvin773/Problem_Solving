#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

int t, k;
string s;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        set<string> S;
        cin >> k >> s;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 1; i+j-1 < s.size(); j++)
            {
                S.insert(s.substr(i, j));
            }
        }

        cout << '#' << tc << ' ';
        auto ans = S.begin();
        if(S.size() < k) cout << "none\n";
        else
        {
            for(int i = 0; i < k-1; i++) ans++;
            cout << *ans << '\n';
        }
    }

    return 0;
}
