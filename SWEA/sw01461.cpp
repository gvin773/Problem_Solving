#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t, n, arr[12][12], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ans, num_conn;

void dfs(int now, vector<pii> &v, int MIN, int conn)
{
    if(now == v.size())
    {
        if(conn >= num_conn)
        {
            ans = (conn > num_conn) ? MIN : min(ans, MIN);
            num_conn = conn;
        }
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int x = v[now].first+dx[i], y = v[now].second+dy[i];
        vector<pii> temp;
        bool flag = true;

        while(0 <= x && x < n && 0 <= y && y < n)
        {
            if(arr[x][y] != 0)
            {
                flag = false;
                break;
            }
            temp.push_back({x, y});
            x += dx[i], y += dy[i];
        }

        if(flag)
        {
            for(auto pos : temp) arr[pos.first][pos.second] = 2;
            dfs(now+1, v, MIN+temp.size(), conn+1);
            for(auto pos : temp) arr[pos.first][pos.second] = 0;
        }
    }

    dfs(now+1, v, MIN, conn);
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        vector<pii> v;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] && !(i == 0 || i == n-1 || j == 0 || j == n-1)) v.push_back({i, j});
            }
        }

        ans = 987654321;
        num_conn = 0;
        dfs(0, v, 0, 0);

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
