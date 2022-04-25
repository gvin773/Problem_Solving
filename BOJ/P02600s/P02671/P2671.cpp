#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;

typedef long long ll;

regex re("(100+1+|01)+");
int t;
string str;

int main()
{
    onlycc;
    cin >> str;
    if(regex_match(str, re)) cout << "SUBMARINE" << '\n';
    else cout << "NOISE" << '\n';

    return 0;
}
