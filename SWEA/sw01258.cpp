#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int t, n, arr[100][100];
bool visited[100][100];

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        vector<pair<int, pair<int, int>>> ans;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
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

                ans.push_back({x*y, {x, y}});
            }
        }

        sort(ans.begin(), ans.end());
        cout << '#' << tc << ' ' << ans.size() << ' ';
        for(auto i : ans) cout << i.second.first << ' ' << i.second.second << ' ';
        cout << '\n';
    }

    return 0;
}
