#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, graph[100][100];

int dfs(int cur, int target, bool visited[], int cnt)
{
    if(cur == target && cnt == 1) return 1;
    if(visited[cur] == true) return 0;

    visited[cur] = true;
    for(int i = 0; i < n; i++)
    {
        if(graph[cur][i] == 1)
            if(dfs(i, target, visited, 1)) return 1;
    }
    return 0;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool visited[100] = {};
            if(dfs(i, j, visited, 0)) cout << 1 << ' ';
            else cout << 0 << ' ';
        }

        cout << '\n';
    }

    return 0;
}
