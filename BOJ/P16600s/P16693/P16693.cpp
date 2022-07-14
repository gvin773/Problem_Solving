#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a1, p1, r1, p2;

int main()
{
    onlycc;
    cin >> a1 >> p1 >> r1 >> p2;
    if(a1*p2 > M_PI*r1*r1*p1) cout << "Slice of pizza";
    else cout << "Whole pizza";

    return 0;
}
