#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, bef[30][30], aft[30][30], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool visited[30][30], ans;
vector<pii> v;

void dfs(int a, int b)
{
    if(a < 0 || a >= n || b < 0 || b >= m) return;
    if(visited[a][b]) return;

    v.push_back(make_pair(a, b));
    visited[a][b] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = a + dx[i], ny = b + dy[i];
        if(bef[a][b] == bef[nx][ny]) dfs(nx, ny);
    }
}

bool check()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(bef[i][j] != aft[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> bef[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> aft[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                while(!v.empty()) v.pop_back();
                dfs(i, j);
                //for(auto pos : v) cout << pos.first << ' ' << pos.second << endl;

                int temp = bef[i][j];
                for(auto pos : v)
                {
                    bef[pos.first][pos.second] = aft[i][j];
                }
                if(check())
                {
                    cout << "YES";
                    return 0;
                }
                for(auto pos : v)
                {
                    bef[pos.first][pos.second] = temp;
                }
            }
        }
    }

    cout << "NO";

    return 0;
}
