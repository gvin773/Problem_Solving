#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#define M 1234567891
#define r 31
using namespace std;

typedef long long ll;

ll pow(int x, int y)
{
    if(y == 0) return 1;
    return (pow(x, y-1)%M * x%M) % M;
}

string str;
ll l, ret;

int main()
{
    onlycc;
    cin >> l >> str;
    for(int i = 0; i < str.size(); i++)
        ret = (ret%M + ((ll)(str[i]-'a'+1)*pow(r, i))%M) % M;

    cout << ret << endl;

    return 0;
}
