#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

int t, n, arr[100][100], dp[25][25];
bool visited[100][100];

int mul(int l, int r, vector<pair<int, int>> &ans)
{
    if(dp[l][r] != -1) return dp[l][r];
    if(l+1 == r) return dp[l][r] = ans[l].first * ans[l].second * ans[r].second;
    if(l == r) return 0;

    int &ret = dp[l][r] = 987654321;
    for(int i = l; i < r; i++)
        ret = min(ret, mul(l, i, ans) + mul(i+1, r, ans) + ans[l].first*ans[i].second*ans[r].second);

    return ret;
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        vector<pair<int, int>> v, ans;
        set<int> s;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin >> arr[i][j];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j] || !arr[i][j]) continue;
                int x = 0, y = 0;
                for(; arr[i+x][j] != 0 && i+x < n; x++) ;
                for(; arr[i][j+y] != 0 && j+y < n; y++) ;
                for(int I = 0; I < x; I++)
                    for(int J = 0; J < y; J++) visited[i+I][j+J] = true;

                v.push_back({x, y});
                s.insert(y);
            }
        }

        int now;
        for(auto i = v.begin(); i != v.end(); i++)
        {
            if(s.find(i->first) == s.end())
            {
                ans.push_back(*i);
                now = i->second;
                v.erase(i);
                break;
            }
        }

        while(!v.empty())
        {
            for(auto i = v.begin(); i != v.end(); i++)
            {
                if(i->first == now)
                {
                    ans.push_back(*i);
                    now = i->second;
                    v.erase(i);
                    break;
                }
            }
        }

        cout << '#' << tc << ' ' << mul(0, ans.size()-1, ans) << '\n';
    }

    return 0;
}
