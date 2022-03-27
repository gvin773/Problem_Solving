#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int x, sum;

int main()
{
    onlycc;
    for(int i = 0; i < 4; i++)
    {
        cin >> x;
        sum += x;
    }
    cout << sum/60 << '\n' << sum%60;

    return 0;
}
