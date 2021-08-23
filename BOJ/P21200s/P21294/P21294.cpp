#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

int n;
string str;

int main()
{
    onlycc;
    cin >> n;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    for(int i = 0; i < n; i++)
    {
        getline(cin, str);
        if(str == "2") cout << '\n';
    }

    return 0;
}
