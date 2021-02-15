#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, cnt;
string A[50], B[50];
bool dif[50][50];

bool eq()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!dif[i][j]) return false;
    return true;
}

void change(int x, int y)
{
    for(int i = x; i < x+3; i++)
        for(int j = y; j < y+3; j++)
            dif[i][j] = !dif[i][j];
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dif[i][j] = (A[i][j] == B[i][j]);

    if(n < 3 || m < 3)
    {
        if(eq()) cout << 0;
        else cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i+2 < n && j+2 < m && !dif[i][j])
            {
                change(i, j);
                cnt++;
            }
        }
    }

    if(eq()) cout << cnt;
    else cout << -1;

    return 0;
}
