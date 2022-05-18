#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, a, b;

int main()
{
    onlycc;
    cin >> n >> a >> b;
    cout << min(a/2+b, n);

    return 0;
}
