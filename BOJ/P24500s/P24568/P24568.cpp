#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int r, s;

int main()
{
    onlycc;
    cin >> r >> s;
    cout << r*8+s*3-28;

    return 0;
}
