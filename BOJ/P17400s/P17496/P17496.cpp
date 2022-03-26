#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, t, c, p;

int main()
{
    onlycc;
    cin >> n >> t >> c >> p;
    cout << (n-1)/t*c*p;

    return 0;
}
