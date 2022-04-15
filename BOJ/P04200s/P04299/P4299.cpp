#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    if(a+b < 0 || a-b < 0 || ((a+b) & 1) || ((a-b) & 1)) cout << -1;
    else cout << (a+b)/2 << ' ' << (a-b)/2;

    return 0;
}
