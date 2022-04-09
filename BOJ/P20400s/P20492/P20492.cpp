#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

double n;

int main()
{
    onlycc;
    cin >> n;
    cout << int(n*0.78) << ' ' << int(n*0.956);

    return 0;
}
