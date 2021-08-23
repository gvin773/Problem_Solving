#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n, ans, pos[15];
bool board[15][15], a[15];

void track(int x, int y)
{
    if(x == n)
    {
        ans++;
        return;
    }
    if(y == n) return;

    bool possible = true;
    if(a[y] == true) possible = false;
    for(int i = 0; i < x; i++)
    {
        if(abs(x-i) == abs(y-pos[i]))
        {
            possible = false;
            break;
        }
    }

    if(possible)
    {
        board[x][y] = true;
        a[y] = true, pos[x] = y;
        track(x+1, 0);
        board[x][y] = false;
        a[y] = false, pos[x] = 464646;
    }

    track(x, y+1);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < 15; i++) pos[i] = 464646;
    track(0, 0);
    cout << ans;

    return 0;
}
