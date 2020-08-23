#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, a, b;

int gcd(int a, int b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;
        cout << a*b/gcd(max(a,b), min(a,b)) << '\n';
    }

    return 0;
}
