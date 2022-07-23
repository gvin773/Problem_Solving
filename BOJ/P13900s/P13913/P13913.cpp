#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

int n, k, Prev[100001];
bool visited[100001];
queue<int> q;
vector<int> v;

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
                Prev[now-1] = now;
            }

            if(now+1 <= 100000 && !visited[now+1])
            {
                q.push(now+1);
                visited[now+1] = true;
                Prev[now+1] = now;
            }
            if(2*now <= 100000 && !visited[2*now])
            {
                q.push(2*now);
                visited[2*now] = true;
                Prev[2*now] = now;
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
    cout << bfs() << '\n';
    while(k != n)
    {
        v.push_back(k);
        k = Prev[k];
    }
    v.push_back(n);
    for(auto i = v.rbegin(); i != v.rend(); i++) cout << *i << ' ';

    return 0;
}
