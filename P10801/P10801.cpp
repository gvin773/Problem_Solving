#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a[10], b[10], ans;

int main()
{
    onlycc;
    for(int i = 0; i < 10; i++) cin >> a[i];
    for(int i = 0; i < 10; i++) cin >> b[i];

    for(int i = 0; i < 10; i++)
    {
        if(a[i] > b[i]) ans++;
        else if(a[i] < b[i]) ans--;
    }

    if(ans > 0) cout << 'A';
    else if(ans < 0) cout << 'B';
    else cout << 'D';

    return 0;
}
