#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int x, p[6] = {1, 1, 2, 2, 2, 8};

int main()
{
    onlycc;
    for(int i = 0; i < 6; i++)
    {
        cin >> x;
        cout << p[i]-x << ' ';
    }

    return 0;
}
