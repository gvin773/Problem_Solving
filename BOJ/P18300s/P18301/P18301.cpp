#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int a, b, c;

int main()
{
    onlycc;
    cin >> a >> b >> c;
    cout << int(floor((a+1)*(b+1)/(double)(c+1)-1));

    return 0;
}
