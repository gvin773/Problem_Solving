#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a[3];

int main()
{
    onlycc;
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a+3);
    for(int i = 0; i < 3; i++) cout << a[i] << ' ';
    return 0;
}
