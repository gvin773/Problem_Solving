#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, k;
bool visited[100001];
priority_queue<pii, vector<pii>, greater<pii>> q;

int bfs()
{
    q.push({0,n});
    visited[n] = true;

    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.top().second;
            int level = q.top().first;
            if(now == k) return level;
            q.pop();

            if(2*now <= 100000 && !visited[2*now])
            {
                q.push({level,2*now});
                visited[2*now] = true;
            }
            if(now-1 >= 0 && !visited[now-1])
            {
                q.push({level+1,now-1});
                visited[now-1] = true;
            }

            if(now+1 <= 100000 && !visited[now+1])
            {
                q.push({level+1,now+1});
                visited[now+1] = true;
            }
        }
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
