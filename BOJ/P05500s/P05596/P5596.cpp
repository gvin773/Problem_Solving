#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b, c;

int main()
{
    onlycc;
    for(int i = 0; i < 4; i++)
    {
        cin >> a;
        b += a;
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> a;
        c += a;
    }
    cout << (b >= c ? b : c);

    return 0;
}
