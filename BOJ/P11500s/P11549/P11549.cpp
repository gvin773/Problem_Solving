#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, a, b, c, d, e;

int main()
{
    onlycc;
    cin >> t >> a >> b >> c >> d >> e;
    cout << (a==t)+(b==t)+(c==t)+(d==t)+(e==t);

    return 0;
}
