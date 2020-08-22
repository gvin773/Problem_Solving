#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string a, b, c, d, ab, cd;

int main()
{
    onlycc;
    cin >> a >> b >> c >> d;
    ab = a + b;
    cd = c + d;

    cout << stoll(ab) +stoll(cd);

    return 0;
}
