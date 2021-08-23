#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string s, ret[1000];

int main()
{
    onlycc;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        ret[i] = s.substr(i, s.size());
    }

    sort(ret, ret+s.size());
    for(int i = 0; i < s.size(); i++)
        cout << ret[i] << '\n';

    return 0;
}
