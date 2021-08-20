#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

/*
set을 사용해 TLE를 막아준다.
*/

int n, m;
set<string> sn, ans;
string s;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        sn.insert(s);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> s;
        if(sn.find(s) != sn.end()) ans.insert(s);
    }

    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << '\n';

    return 0;
}
