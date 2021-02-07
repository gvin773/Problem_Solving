#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int board[9][9];
vector<pair<int, int>> v;

void track(int x, int y, int now)
{
    if(now == v.size())
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    bool a[10] = {};
    for(int i = 0; i < 9; i++)
    {
        a[board[i][y]] = true;
        a[board[x][i]] = true;
    }

    int sx = x - x%3, sy = y - y%3;
    for(int i = sx; i < sx+3; i++)
        for(int j = sy; j < sy+3; j++)
            a[board[i][j]] = true;

    for(int i = 1; i < 10; i++)
    {
        if(a[i] != true)
        {
            board[x][y] = i;
            track(v[now+1].first, v[now+1].second, now+1);
            board[x][y] = 0;
        }
    }
}

int main()
{
    onlycc;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 0) v.push_back({i, j});
        }

    track(v[0].first, v[0].second, 0);
    return 0;
}
