#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
백트래킹을 이용하여 시간복잡도를 단축시켜 준다.
*/

int r, c, cnt, ans;
string board[20];
bool a[100];
int d1[4] = {0, 0, 1, -1}, d2[4] = {1, -1, 0, 0};

void track(int x, int y)
{
    a[board[x][y]] = true;
    cnt++;
    ans = max(ans, cnt);
    for(int i = 0; i < 4; i++)
    {
        if((0 <= x+d1[i] && x+d1[i] < r) && (0 <= y+d2[i] && y+d2[i] < c) && a[board[x+d1[i]][y+d2[i]]] != true)
        {
            track(x+d1[i], y+d2[i]);
            a[board[x+d1[i]][y+d2[i]]] = false;
            cnt--;
        }
    }
}

int main()
{
    onlycc;
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> board[i];
    track(0, 0);
    cout << ans;

    return 0;
}
