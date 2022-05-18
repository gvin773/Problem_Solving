#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string s;

int main()
{
    onlycc;
    getline(cin, s);
    if((int)s[0] + (int)s[4] == (int)s[8] + (int)'0') cout << "YES";
    else cout << "NO";

    return 0;
}
