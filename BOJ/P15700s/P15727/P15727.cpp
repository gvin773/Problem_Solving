#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int l;

int main()
{
    onlycc;
    cin >> l;
    cout << l/5+!!(l%5);

    return 0;
}
