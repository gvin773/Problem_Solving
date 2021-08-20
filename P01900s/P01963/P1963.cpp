#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int t, a, b;
bool prime[10001];

int change(int n, int target, int i)
{
    int num[4] = {n/1000, n%1000/100, n%100/10, n%10};
    num[i] = target;
    return num[0]*1000+num[1]*100+num[2]*10+num[3];
}

int bfs(queue<int> &q, bool visited[])
{
    visited[a] = true;
    q.push(a);

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            int now = q.front();
            if(now == b) return level;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j <= 9; j++)
                {
                    int next = change(now, j, i);
                    if(next/1000 != 0 && !visited[next] && !prime[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

        }
        level++;
    }

    return 46464646;
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 2; i*i <= 10000; i++)
    {
            for(int j = 2; prime[i] != true && i*j <= 10000; j++)
                prime[i*j] = true;
    }

    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;
        queue<int> q;
        bool visited[10001] = {};
        int ans = 0;
        if((ans = bfs(q, visited)) != 46464646) cout << ans << '\n';
        else cout << "Impossible\n";
    }

    return 0;
}
