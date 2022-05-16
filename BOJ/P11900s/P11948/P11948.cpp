#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a[4], b[2], s1, s2;

int main()
{
    onlycc;
    for(int i = 0; i < 4; i++)
    {
        cin >> a[i];
        s1 += a[i];
    }
    for(int i = 0; i < 2; i++)
    {
        cin >> b[i];
        s2 += b[i];
    }
    sort(a, a+4);
    sort(b, b+2);
    cout << s1-a[0]+s2-b[0];

    return 0;
}
