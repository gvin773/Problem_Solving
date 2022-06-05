#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int ca, ba, pa, cr, br, pr;

int main()
{
    onlycc;
    cin >> ca >> ba >> pa >> cr >> br >> pr;
    cout << max(cr-ca, 0) + max(br-ba, 0) + max(pr-pa, 0);

    return 0;
}
