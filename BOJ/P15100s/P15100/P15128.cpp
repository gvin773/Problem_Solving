#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll p1, q1, p2, q2;

int main()
{
    onlycc;
    cin >> p1 >> q1 >> p2 >> q2;
    cout << !((p1*p2)%(q1*q2*2));

    return 0;
}
