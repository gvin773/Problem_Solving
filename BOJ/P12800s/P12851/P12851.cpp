#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, k, ans = 987654321, num;
bool visited[100001];
queue<int> q;

void bfs()
{
    q.push(n);
    visited[n] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            if(level > ans) return;
            if(now == k)
            {
                ans = level;
                num++;
            }
            visited[now] = true;
            q.pop();

            if(now-1 >= 0 && !visited[now-1]) q.push(now-1);
            if(now+1 <= 100000 && !visited[now+1]) q.push(now+1);
            if(2*now <= 100000 && !visited[2*now]) q.push(2*now);
        }
        level++;
    }
}

int main()
{
    onlycc;
    cin >> n >> k;
    bfs();
    cout << ans << '\n' << num;

    return 0;
}
