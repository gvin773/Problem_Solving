#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int equation_1[3], equation_2[3], new_equ[3], x, y;

int main()
{
    onlycc;
    for(int i = 0; i < 3; i++) cin >> equation_1[i];
    for(int i = 0; i < 3; i++) cin >> equation_2[i];

    if(equation_1[0] == 0)
    {
        y = equation_1[2]/equation_1[1];
        x = (equation_2[2]-equation_2[1]*y)/equation_2[0];
        cout << x << ' ' << y;
    }

    else if(equation_1[1] == 0)
    {
        x = equation_1[2]/equation_1[0];
        y = (equation_2[2]-equation_2[0]*x)/equation_2[1];
        cout << x << ' ' << y;
    }

    else if(equation_2[0] == 0)
    {
        y = equation_2[2]/equation_2[1];
        x = (equation_1[2]-equation_1[1]*y)/equation_1[0];
        cout << x << ' ' << y;
    }

    else if(equation_2[1] == 0)
    {
        x = equation_2[2]/equation_2[0];
        y = (equation_1[2]-equation_1[0]*x)/equation_1[1];
        cout << x << ' ' << y;
    }

    else
    {
        int temp = equation_1[0];
        for(int i = 0; i < 3; i++) equation_1[i] *= equation_2[0];
        for(int i = 0; i < 3; i++) equation_2[i] *= temp;
        for(int i = 0; i < 3; i++) new_equ[i] = equation_1[i] - equation_2[i];

        y = new_equ[2] / new_equ[1];
        x = (equation_1[2] - y * equation_1[1]) / equation_1[0];
        cout << x << ' ' << y;
    }

    return 0;
}
