#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m, ans;
string str;
set<string> s;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        s.insert(str);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> str;
        if(s.find(str) != s.end()) ans++;
    }
    cout << ans;

    return 0;
}
