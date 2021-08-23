#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int r, c, arr[100][100], sarr[100][100];
bool im;

int main()
{
    onlycc;
    cin >> r >> c;
    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++) cin >> arr[i][j];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) cin >> sarr[i][j];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(sarr[i][j] != arr[c-1-j][i])
            {
                im = true;
                goto xy;
            }
        }
    }

    xy:
        if(im)
        {
            cout << "|>___/|     /}\n";
            cout << "| O O |    / }\n";
            cout << "( =0= )\"\"\"\"  \\\n";
            cout << "| ^  ____    |\n";
            cout << "|_|_/    ||__|";
        }
        else
        {
            cout << "|>___/|        /}\n";
            cout << "| O < |       / }\n";
            cout << "(==0==)------/ }\n";
            cout << "| ^  _____    |\n";
            cout << "|_|_/     ||__|";
        }

    return 0;
}
