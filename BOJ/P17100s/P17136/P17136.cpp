#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

/*
위에서부터 각 종이 크기를 이용하여 백트래킹, 각 종이별로 사용가능한 최대 개수가 정해져 있으므로,
그것보다 많이 사용하면 끊어준다.
*/

bool paper[10][10], visited[10][10];
int ans = -1, cnt, p[6];
vector<pair<int, int>> v;

void filling(int s, int x, int y, bool b)
{
    for(int i = x; i < x+s; i++)
        for(int j = y; j < y+s; j++)
            visited[i][j] = b;
}

bool check(int s, int x, int y)
{
    if(!(x+s < 11 && y+s < 11)) return false;

    for(int i = x; i < x+s; i++)
        for(int j = y; j < y+s; j++)
            if(paper[i][j] == false || visited[i][j] == true) return false;
    return true;
}

void track(int index)
{
    if(index == v.size())
    {
        if(ans == -1) ans = cnt;
        else ans = min(ans, cnt);
        return;
    }

    int x = v[index].first, y = v[index].second;
    if(visited[x][y])
    {
        track(index+1);
        return;
    }

    if(p[1] <= 4)
    {
    visited[x][y] = true;
    cnt++, p[1]++;
    track(index+1);
    visited[x][y] = false;
    cnt--, p[1]--;
    }

    if(p[2] <= 4 && check(2, x, y))
    {
        filling(2, x, y, true);
        cnt++, p[2]++;
        track(index+1);
        filling(2, x, y, false);
        cnt--, p[2]--;
    }

    if(p[3] <= 4 && check(3, x, y))
    {
        filling(3, x, y, true);
        cnt++, p[3]++;
        track(index+1);
        filling(3, x, y, false);
        cnt--, p[3]--;
    }

    if(p[4] <= 4 && check(4, x, y))
    {
        filling(4, x, y, true);
        cnt++, p[4]++;
        track(index+1);
        filling(4, x, y, false);
        cnt--, p[4]--;
    }

    if(p[5] <= 4 && check(5, x, y))
    {
        filling(5, x, y, true);
        cnt++, p[5]++;
        track(index+1);
        filling(5, x, y, false);
        cnt--, p[5]--;
    }
}

int main()
{
    onlycc;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            cin >> paper[i][j];
            if(paper[i][j]) v.push_back({i, j});
        }

    if(v.empty()) cout << 0;
    else
    {
        track(0);
        cout << ans;
    }

    return 0;
}
