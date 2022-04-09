#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll a, s;

int main()
{
    onlycc;
    for(int i = 0; i < 6; i++)
    {
        cin >> a;
        s += a;
    }
    cout << s*5;

    return 0;
}
