#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;

typedef long long ll;

int r, c, x, y;
string board[100], order;
vector<pair<int, int>> v;

bool check(int a, int b)
{
    if(0 <= a && a < r && 0 <= b && b < c) return true;
    else return false;
}

int dis(int r2, int s2)
{
    return abs(x-r2) + abs(y-s2);
}

int main()
{
    onlycc;
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> board[i];
    cin >> order;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == 'R') v.push_back({i, j});
            if(board[i][j] == 'I')
            {
                x = i;
                y = j;
            }
        }
    }

    for(int i = 0;  i < order.size(); i++)
    {
        if(order[i] == '1')
        {
            x += 1;
            y -= 1;
        }
        else if(order[i] == '2') x += 1;
        else if(order[i] == '3')
        {
            x += 1;
            y += 1;
        }
        else if(order[i] == '4') y -= 1;
        else if(order[i] == '6') y += 1;
        else if(order[i] == '7')
        {
            x -= 1;
            y -= 1;
        }
        else if(order[i] == '8') x -= 1;
        else if(order[i] == '9')
        {
            x -= 1;
            y += 1;
        }

        if(find(v.begin(), v.end(), make_pair(x, y)) != v.end())
        {
            cout << "kraj " << i+1;
            return 0;
        }

        multiset<pair<int, int>> s;
        for(auto iter = v.begin(); iter != v.end(); iter++)
        {
            int X = iter->first, Y = iter->second, nx = 1000, ny = 1000;
            if(check(X-1, Y-1) && dis(X-1, Y-1) < dis(nx, ny))
            {
                nx = X-1;
                ny = Y-1;
            }
            if(check(X-1, Y) && dis(X-1, Y) < dis(nx, ny))
            {
                nx = X-1;
                ny = Y;
            }
            if(check(X-1, Y+1) && dis(X-1, Y+1) < dis(nx, ny))
            {
                nx = X-1;
                ny = Y+1;
            }
            if(check(X, Y-1) && dis(X, Y-1) < dis(nx, ny))
            {
                nx = X;
                ny = Y-1;
            }
            if(check(X, Y+1) && dis(X, Y+1) < dis(nx, ny))
            {
                nx = X;
                ny = Y+1;
            }
            if(check(X+1, Y-1) && dis(X+1, Y-1) < dis(nx, ny))
            {
                nx = X+1;
                ny = Y-1;
            }
            if(check(X+1, Y) && dis(X+1, Y) < dis(nx, ny))
            {
                nx = X+1;
                ny = Y;
            }
            if(check(X+1, Y+1) && dis(X+1, Y+1) < dis(nx, ny))
            {
                nx = X+1;
                ny = Y+1;
            }

            if(nx == x && ny == y)
            {
                cout << "kraj " << i+1;
                return 0;
            }

            s.insert({nx, ny});
        }

        for(auto iter = s.begin(); iter != s.end();)
        {
            int aa = iter->first, bb = iter->second;
            if(s.count({aa, bb}) > 1)
            {
                while(iter->first != aa || iter->second != bb) iter++;
                s.erase({aa, bb});
            }
            else iter++;
        }

        v.assign(s.begin(), s.end());
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(find(v.begin(), v.end(), make_pair(i, j)) != v.end()) board[i][j] = 'R';
            else board[i][j] = '.';
        }
    }
    board[x][y] = 'I';

    for(int i = 0; i < r; i++) cout << board[i] << '\n';

    return 0;
}
