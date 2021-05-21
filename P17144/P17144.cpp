#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int r, c, t, a[50][50], ans, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, air;
int ur, ul, dr, dl;

void spread()
{
    int next[50][50] = {};
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(a[i][j] > 0)
            {
                int cnt = 0;
                for(int k = 0; k < 4; k++)
                {
                    int nx = i+dx[k], ny = j+dy[k];
                    if(0 <= nx && nx < r && 0 <= ny && ny < c && a[nx][ny] != -1)
                    {
                        next[nx][ny] += (a[i][j]/5);
                        cnt++;
                    }
                }
                a[i][j] -= (a[i][j]/5*cnt);
                if(a[i][j] < 0) a[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) a[i][j] += next[i][j];
}

void wind()
{
    ur = a[air][c-1], dr = a[r-1][c-1], dl = a[r-1][0];
    for(int i = c-1; i >= 0; i--)
    {
        if(i == 0) a[air][i] = -1;
        else if(i == 1) a[air][i] = 0;
        else a[air][i] = a[air][i-1];
    }
    for(int i = r-1; i > air; i--)
    {
        if(i == air+1) a[i][c-1] = ur;
        else a[i][c-1] = a[i-1][c-1];
    }
    for(int i = 0; i < c-1; i++)
    {
        if(i == c-2) a[r-1][i] = dr;
        else a[r-1][i] = a[r-1][i+1];
    }
    for(int i = air+1; i < r-1; i++)
    {
        if(i == r-2) a[i][0] = dl;
        else a[i][0] = a[i+1][0];
    }

    air--;

    ul = a[0][0], ur = a[0][c-1], dr = a[air][c-1];
    for(int i = c-1; i >= 0; i--)
    {
        if(i == 0) a[air][i] = -1;
        else if(i == 1) a[air][i] = 0;
        else a[air][i] = a[air][i-1];
    }
    for(int i = 0; i < air; i++)
    {
        if(i == air-1) a[i][c-1] = dr;
        else a[i][c-1] = a[i+1][c-1];
    }
    for(int i = 0; i < c-1; i++)
    {
        if(i == c-2) a[0][i] = ur;
        else a[0][i] = a[0][i+1];
    }

    for(int i = air-1; i > 0; i--)
    {
        if(i == 1) a[i][0] = ul;
        else a[i][0] = a[i-1][0];
    }

    air++;
}

int main()
{
    onlycc;
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == -1) air = i;
        }
    }

    for(int i = 0; i < t; i++)
    {
        spread();
        wind();
    }

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) if(a[i][j] != -1) ans += a[i][j];

    cout << ans;

    return 0;
}
