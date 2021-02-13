#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

int t, n, arr[1001], cnt;
bool visited[1001], finished[1001];

void dfs(int now)
{
    visited[now] = true;
    int next = arr[now];
    if(visited[next]) if(!finished[next]) cnt++;
    else dfs(next);
    finished[now] = true;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        cnt = 0;
        cin >> n;
        for(int j = 1; j <= n; j++) cin >> arr[j];
        for(int j = 1; j <= n; j++) if(!visited[j]) dfs(j);
        cout << cnt << '\n';
    }

    return 0;
}
