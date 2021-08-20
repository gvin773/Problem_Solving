#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, m;

int main()
{
    onlycc;
    cin >> n >> m;
    if(n == 1 || m == 1) cout << 1;
    else if(m <= 6)
    {
        if(n == 2) cout << ceil(m/(double)2);
        else cout << (m<=4 ? m : 4);
    }
    else if(m == 7)
    {
        if(n == 2) cout << ceil(m/(double)2);
        else cout << 5;
    }
    else
    {
        if(n == 2) cout << 4;
        else cout << m-2;
    }

    return 0;
}
