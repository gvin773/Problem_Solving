#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

vector<int> nodes[200001];
queue<int> q, temp;
int rumor[200001];
int n, m, a, time;

void bfs()
{
    time++;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            q.pop();
            for(int next : nodes[now])
            {
                if(rumor[next] == -1)
                {
                    int cnt = 0;
                    for(int nnext : nodes[next])
                        if(rumor[nnext] != -1) cnt++;

                    if(cnt >= nodes[next].size()/(float)2)
                    {
                        q.push(next);
                        temp.push(next);
                    }
                }
            }
        }

        while(!temp.empty())
        {
            rumor[temp.front()] = time;
            temp.pop();
        }
        time++;
    }
}

int main()
{
    onlycc;
    cin >> n;
    memset(rumor, -1, sizeof(rumor));
    for(int i = 1; i <= n;)
    {
        cin >> a;
        if(a) nodes[i].push_back(a);
        else i++;
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a;
        rumor[a] = time;
        q.push(a);
    }

    bfs();
    for(int i = 1; i <= n; i++) cout << rumor[i] << ' ';

    return 0;
}
