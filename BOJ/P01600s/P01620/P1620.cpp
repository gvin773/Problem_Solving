#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
map<string, int> x;
map<int, string> y;
string s;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        x[s] = i;
        y[i] = s;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> s;
        if('0' <= s[0] && s[0] <= '9') cout << y[stoi(s)];
        else cout << x[s];
        cout << '\n';
    }

    return 0;
}
