#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int b, ret;
string n;

int main()
{
    onlycc;
    cin >> n >> b;

    int k = 0;
    for(int i = n.size()-1; i >= 0; i--)
    {
        if('A' <= n[i] && n[i] <= 'Z')
            ret += (int)(n[i]-'A'+10)*(int)pow(b, k);

        else if('0' <= n[i] && n[i] <= '9')
            ret += (int)(n[i]-'0')*(int)pow(b, k);

        k++;
    }

    cout << ret;

    return 0;
}
