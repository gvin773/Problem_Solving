#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    if(a.size() < b.size()) cout << "no";
    else cout << "go";

    return 0;
}
