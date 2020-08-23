#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

string n, fin;

int main()
{
    onlycc;
    cin >> n;
    if(n.size() % 3 == 0)
        fin = n;

    else
    {
        for(int i = 0; i < 3-n.size()%3; i++)
            fin += '0';

        fin += n;
    }

    for(int i = 0; i < fin.size(); i+=3)
    {
        int ret = 0;
        ret += (fin[i]-'0')*4;
        ret += (fin[i+1]-'0')*2;
        ret += (fin[i+2]-'0');

        cout << ret;
    }

    return 0;
}
