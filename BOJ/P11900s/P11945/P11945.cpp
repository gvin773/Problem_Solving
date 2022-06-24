#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
string s;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }

    return 0;
}
