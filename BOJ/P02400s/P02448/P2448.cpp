#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int n, temp, k;
char star[3100][6200];

void make(int lx, int ly, int K)
{
    if(K == 0)
    {
        for(int i = 0; i < 5; i++) star[lx][ly+i] = '*'; //1st floor
        star[lx-1][ly+1] = star[lx-1][ly+3] = '*'; //2nd floor
        star[lx-2][ly+2] = '*'; //top
        return;
    }

    make(lx, ly, K-1); //down left
    make(lx, ly + 6*pow(2, K-1), K-1); //down right
    make(lx - 3*pow(2, K-1), ly + 3*pow(2, K-1), K-1); //up
}

int main()
{
    onlycc;
    cin >> n;
    temp = n;
    while(temp%2 == 0)
    {
        k++;
        temp /= 2;
    }

    make(n-1, 0, k);
    int len = 6*pow(2, k)-1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(star[i][j] != '\0') cout << star[i][j];
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
