#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, a[2300000];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i*n+j];
    sort(a, a+n*n);
    cout << a[n*n-n];

    return 0;
}
