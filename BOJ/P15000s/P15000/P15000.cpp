#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main()
{
    onlycc;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s;

    return 0;
}
