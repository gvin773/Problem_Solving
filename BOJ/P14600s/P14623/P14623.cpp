#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

typedef long long ll;

string s1, s2, s3;
bool flag;

int main()
{
    onlycc;
    cin >> s1 >> s2;
    bitset<30> bs1(s1), bs2(s2);
    bitset<80> bs3(bs1.to_ullong() * bs2.to_ullong());
    s3 = bs3.to_string();
    for(int i = 0; i < s3.size(); i++)
    {
        if(s3[i] == '1') flag = true;
        if(flag) cout << s3[i];
    }
    if(!flag) cout << 0;

    return 0;
}
