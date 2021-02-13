#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll num[2000000], n, m;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n+m; i++) cin >> num[i];
    sort(num, num+n+m);
    for(int i = 0; i < n+m; i++) cout << num[i] << ' ';

    return 0;
}
