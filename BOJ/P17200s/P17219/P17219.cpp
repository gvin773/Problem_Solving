#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
map<string, string> x;
string s, t;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> t;
        x[s] = t;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> s;
        cout << x[s] << '\n';
    }

    return 0;
}
