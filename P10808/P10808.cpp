#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string str;
int eng[26];

int main()
{
    onlycc;
    cin >> str;

    for(int i = 0; i < str.size(); i++)
        eng[str[i]-'a']++;


    for(int i = 0; i < 26; i++)
        cout << eng[i] << ' ';

    return 0;
}
