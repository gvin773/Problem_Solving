#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    cout << (a*(100-b)/100 >= 100 ? 0 : 1);

    return 0;
}
