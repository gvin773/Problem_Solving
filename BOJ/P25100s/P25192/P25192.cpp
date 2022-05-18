#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

ll n, ans;
string s;
set<string> S;
bool disable;

int main()
{
    onlycc;
    cin >> n;
    cin >> s;
    for(int i = 1; i < n; i++)
    {
        cin >> s;
        if(s == "ENTER")
        {
            disable = false;
            S.clear();
        }
        else if(S.find(s) == S.end())
        {
            ans++;
            S.insert(s);
        }
    }
    cout << ans;

    return 0;
}
