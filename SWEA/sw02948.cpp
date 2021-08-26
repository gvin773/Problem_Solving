#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long ll;

int t, n, m, ans;
string str;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        unordered_map<string, bool> M;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> str;
            M[str] = 1;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> str;
            if(M.find(str) != M.end()) ans++;
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
