#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int r, c, k, ans, a[4] = {0, 0, 1, -1}, b[4] = {1, -1, 0, 0}, cnt;
string board[5];
bool visited[5][5];

void track(int x, int y)
{
    if(x == 0 && y == c-1)
    {
        if(cnt+1 == k) ans++;
        return;
    }

    visited[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nextx = x+a[i], nexty = y+b[i];
        if(0 <= nextx && nextx < r && 0 <= nexty && nexty < c
           && board[nextx][nexty] == '.' && !visited[nextx][nexty])
        {
            cnt++;
            track(nextx, nexty);
            visited[nextx][nexty] = false;
            cnt--;
        }
    }
}

int main()
{
    onlycc;
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        cin >> board[i];

    track(r-1, 0);
    cout << ans;

    return 0;
}
