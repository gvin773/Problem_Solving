#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n, a[8], ans;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    do {
        int sum = 0;
        for(int i = 0; i < n-1; i++) sum += abs(a[i] - a[i+1]);
        ans = max(ans, sum);
    } while(next_permutation(a, a+n));

    cout << ans;
    return 0;
}
