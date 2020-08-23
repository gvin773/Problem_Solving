#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string n;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n.size(); i++)
    {
        if(n[i] == '0' && i == 0)
        {
            cout << 0;
            continue;
        }

        else if(n[i] == '1' && i == 0)
        {
            cout << 1;
            continue;
        }

        else if(n[i] == '2' && i == 0)
        {
            cout << 10;
            continue;
        }

        else if(n[i] == '3' && i == 0)
        {
            cout << 11;
            continue;
        }

        n[i] -= '0';

        if(n[i] >= 4)
        {
            cout << 1;
            n[i] %= 4;
        }

        else cout << 0;

        if(n[i] >= 2)
        {
            cout << 1;
            n[i] %= 2;
        }

        else cout << 0;

        if(n[i] == 1)
            cout << 1;

        else cout << 0;
    }

    return 0;
}
