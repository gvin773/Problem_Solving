#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int t, n, stu[100001];
bool visited[100001], finished[100001];

void dfs(int cur, int &ret)
{
    if(visited[cur] == true && finished[cur] == false)
    {
        ret++;
        finished[cur] = true;
        dfs(stu[cur], ret);
        return;
    }

    if(visited[cur] == true || finished[cur] == true) return;

    visited[cur] = true;
    dfs(stu[cur], ret);

    finished[cur] = true;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int ret = 0;
        cin >> n;
        for(int j = 1; j <= n; j++)
            cin >> stu[j];

        for(int j = 1; j <= n; j++)
            dfs(j, ret);

        cout << n-ret << '\n';

        for(int j = 1; j <= n; j++)
            visited[j] = finished[j] = false;
    }


    return 0;
}
