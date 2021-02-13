#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, m, ans;
string board[100];

ll get_sum(int x0, int y0, int x, int y)
{
    ll ret = 0;
    for(int i = x0; i <= x; i++)
        for(int j = y0; j <= y; j++) ret += (board[i][j] - '0');
    return ret;
}

void get_max()
{
    for(int i = 0; i < n-2; i++)
        for(int j = i+1; j < n-1; j++)
            ans = max(ans, get_sum(0, 0, i, m-1)*get_sum(i+1, 0, j, m-1)*get_sum(j+1, 0, n-1, m-1));

    for(int i = 0; i < m-2; i++)
        for(int j = i+1; j < m-1; j++)
            ans = max(ans, get_sum(0, 0, n-1, i)*get_sum(0, i+1, n-1, j)*get_sum(0, j+1, n-1, m-1));

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < m-1; j++)
            ans = max(ans, get_sum(0, 0, i, j)*get_sum(i+1, 0, n-1, j)*get_sum(0, j+1, n-1, m-1));

    for(int i = 0; i < m-1; i++)
        for(int j = 0; j < n-1; j++)
            ans = max(ans, get_sum(0, 0, n-1, i)*get_sum(0, i+1, j, m-1)*get_sum(j+1, i+1, n-1, m-1));

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < m-1; j++)
            ans = max(ans, get_sum(0, 0, i, m-1)*get_sum(i+1, 0, n-1, j)*get_sum(i+1, j+1, n-1, m-1));

    for(int i = 0; i < m-1; i++)
        for(int j = 0; j < n-1; j++)
            ans = max(ans, get_sum(0, 0, j, i)*get_sum(0, i+1, j, m-1)*get_sum(j+1, 0, n-1, m-1));
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];

    get_max();
    cout << ans;

    return 0;
}
