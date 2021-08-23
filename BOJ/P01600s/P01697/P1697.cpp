#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, k;
bool visited[100001];
queue<int> q;

int bfs()
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
            if(now == k) return level;
            q.pop();

            if(now-1 >= 0 && !visited[now-1])
            {
                q.push(now-1);
                visited[now-1] = true;
            }

            if(now+1 <= 100000 && !visited[now+1])
            {
                q.push(now+1);
                visited[now+1] = true;
            }
            if(2*now <= 100000 && !visited[2*now])
            {
                q.push(2*now);
                visited[2*now] = true;
            }
        }
        level++;
    }
    return -1;
}

int main()
{
    onlycc;
    cin >> n >> k;
    cout << bfs();

    return 0;
}
