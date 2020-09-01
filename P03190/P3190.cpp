#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

typedef long long ll;

int n, k, l, time, cnt = 1, face; //up1 right2 down3 left4,0
bool apple[101][101];
list<pair<int, int>> snake;
pair<int, char> dir[101];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        apple[a][b] = true;
    }

    cin >> l;
    for(int i = 1; i <= l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        dir[i] = make_pair(x, c);
    }

    snake.push_back(make_pair(1, 1));
    face = 2;

    for(time = 1; ; time++)
    {
        int x, y;
        if(face == 1) //up
        {
            x = snake.front().first-1;
            y = snake.front().second;
        }

        else if(face == 2) //right
        {
            x = snake.front().first;
            y = snake.front().second+1;
        }

        else if(face == 3) //down
        {
            x = snake.front().first+1;
            y = snake.front().second;
        }

        else if(face == 4 || face == 0) //left
        {
            x = snake.front().first;
            y = snake.front().second-1;
        }

        if(x == 0 || y == 0 || x == n+1 || y == n+1)
            break;

        int check = 0;
        for(auto i = snake.begin(); i != snake.end(); i++)
            if(*i == make_pair(x, y))
            {
                check = 1;
                break;
            }

        if(check) break;

        snake.push_front(make_pair(x, y));

        if(apple[x][y] == false)
        {
            auto iter = snake.end();
            iter--;
            snake.erase(iter);
        }

        else apple[x][y] = false;

        if(cnt <= l && dir[cnt].first == time)
        {
            if(face == 0) face = 4;
            if(dir[cnt].second == 'L') face--;
            else if(dir[cnt].second == 'D') face++;
            if(face == 5) face = 1;
            cnt++;
        }
    }

    cout << time;

    return 0;
}
