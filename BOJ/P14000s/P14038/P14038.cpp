#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

char a;
ll b;

int main()
{
    onlycc;
    for(int i = 0; i < 6; i++)
    {
        cin >> a;
        if(a == 'W') b++;
    }
    if(b >= 5) cout << 1;
    else if(b >= 3) cout << 2;
    else if(b >= 1) cout << 3;
    else cout << -1;

    return 0;
}
