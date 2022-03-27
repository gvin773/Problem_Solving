#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, ans;

int main()
{
    onlycc;
    for(int i = 0; i < 5; i++)
    {
        cin >> a;
        ans += a;
    }
    cout << ans;

    return 0;
}
