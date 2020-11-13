#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, m, p, channel[100001];
bool visited[100001], finished[100001];

int dfs(int cur)
{
    if(visited[cur] == true && finished[cur] == false)
    {
        cout << -1;
        exit(0);
    }
    if(channel[cur] == 0 || visited[cur] == true) return 0;

    visited[cur] = true;

    int ret = 1;
    ret += dfs(channel[cur]);

    finished[cur] = true;
    return ret;
}

int main()
{
    onlycc;
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(channel[b] == 0) channel[b] = a;
    }

    cout << dfs(p);

    return 0;
}
