#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, g, d;
string arr[100];
bool visitedg[100][100], visitedd[100][100];

void dfs_g(int x, int y, char c)
{
    if(visitedg[x][y] == true || c != arr[x][y]) return;

    visitedg[x][y] = true;
    if(x != 0) dfs_g(x-1, y, c);
    if(y != 0) dfs_g(x, y-1, c);
    if(x != n-1) dfs_g(x+1, y, c);
    if(y != n-1) dfs_g(x, y+1, c);
}

void dfs_d(int x, int y, char c)
{
    if(visitedd[x][y] == true) return;
    if((c == 'R' || c == 'G') && arr[x][y] == 'B') return;
    if(c == 'B' && arr[x][y] != 'B') return;

    visitedd[x][y] = true;
    if(x != 0) dfs_d(x-1, y, c);
    if(y != 0) dfs_d(x, y-1, c);
    if(x != n-1) dfs_d(x+1, y, c);
    if(y != n-1) dfs_d(x, y+1, c);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(visitedg[i][j] == false)
            {
                g++;
                dfs_g(i, j, arr[i][j]);
            }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(visitedd[i][j] == false)
            {
                d++;
                dfs_d(i, j, arr[i][j]);
            }

    cout << g << ' ' << d;


    return 0;
}
