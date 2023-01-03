#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ld a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    a = a / (b*b);
    if(a > 25) cout << "Overweight";
    else if(a >= 18.5) cout << "Normal weight";
    else cout << "Underweight";

    return 0;
}
