#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a[10];

int main()
{
    onlycc;
    for(int i = 0; i < 10; i++) cin >> a[i];
    for(int i = 0; i < 2; i++) cout << a[5*i+0]*6+a[5*i+1]*3+a[5*i+2]*2+a[5*i+3]+a[5*i+4]*2 << ' ';

    return 0;
}
