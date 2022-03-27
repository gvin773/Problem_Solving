#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n1, k1, n2, k2;

int main()
{
    onlycc;
    cin >> n1 >> k1 >> n2 >> k2;
    cout << n1*k1 + n2*k2;

    return 0;
}
