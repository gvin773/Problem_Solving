#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, k, a[5000000];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);
    cout << a[k-1];

    return 0;
}
