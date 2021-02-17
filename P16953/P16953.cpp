#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

ll a, b;
queue<ll> q;
set<ll> s;

int bfs()
{
    s.insert(a);
    q.push(a);

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            ll now = q.front();
            if(now == b) return level+1;
            q.pop();

            if(now*2 <= b && s.find(now*2) == s.end())
            {
                s.insert(now*2);
                q.push(now*2);
            }

            if(now*10+1 <= b && s.find(now*10+1) == s.end())
            {
                s.insert(now*10+1);
                q.push(now*10+1);
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    onlycc;
    cin >> a >> b;
    cout << bfs();

    return 0;
}
