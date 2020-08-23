#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

unsigned long long a, b;

ll gcd(ll a, ll b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    onlycc;
    cin >> a >> b;
    for(int i = 0; i < gcd(max(a,b), min(a,b)); i++)
        cout << 1;

    return 0;
}
