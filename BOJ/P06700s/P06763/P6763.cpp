#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b;

int main()
{
    onlycc;
    cin >> a >> b;
    if(a >= b) cout << "Congratulations, you are within the speed limit!";
    else
    {
        cout << "You are speeding and your fine is ";
        if(b-a > 30) cout << "$500.";
        else if(b-a > 20) cout << "$270.";
        else cout << "$100.";
    }

    return 0;
}
