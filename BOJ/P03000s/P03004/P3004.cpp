#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n;

int main()
{
    onlycc;
    cin >> n;
    if(n&1) cout << (n/2+1)*(n/2+2);
    else cout << (n/2+1)*(n/2+1);

    return 0;
}
