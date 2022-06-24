#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, d;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d;
    if(b == c && (d == 8 || d == 9) && (a == 8 || a == 9)) cout << "ignore";
    else cout << "answer";

    return 0;
}
