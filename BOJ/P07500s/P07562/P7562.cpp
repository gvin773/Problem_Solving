#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
bfs �̿��Ͽ� ���� ����ϴٰ� ������ �����ϸ� level ���
*����* �׽�Ʈ���̽����� ť, visited �迭 �ʱ�ȭ �ؾ���
*/

int t, l, x0, y0, x, y;

bool check_pos(int a, int b)
{
    if(a == x && b == y) return true;
    else return false;
}

int bfs(queue<pair<int, int>> &q, bool visited[][300])
{
    q.push({x0, y0});
    visited[x0][y0] = true;

    int level = 0;
    pair<int, int> now = {x0, y0};
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            now = q.front();
            if(check_pos(now.first, now.second)) return level;

            if(now.first-2 >= 0 && now.second-1 >= 0 && !visited[now.first-2][now.second-1])
            {
                q.push({now.first-2, now.second-1});
                visited[now.first-2][now.second-1] = true;
            }

            if(now.first-1 >= 0 && now.second-2 >= 0 && !visited[now.first-1][now.second-2])
            {
                q.push({now.first-1, now.second-2});
                visited[now.first-1][now.second-2] = true;
            }

            if(now.first-2 >= 0 && now.second+1 < l && !visited[now.first-2][now.second+1])
            {
                q.push({now.first-2, now.second+1});
                visited[now.first-2][now.second+1] = true;
            }

            if(now.first-1 >= 0 && now.second+2 < l && !visited[now.first-1][now.second+2])
            {
                q.push({now.first-1, now.second+2});
                visited[now.first-1][now.second+2] = true;
            }

            if(now.first+1 < l && now.second-2 >= 0 && !visited[now.first+1][now.second-2])
            {
                q.push({now.first+1, now.second-2});
                visited[now.first+1][now.second-2] = true;
            }

            if(now.first+2 < l && now.second-1 >= 0 && !visited[now.first+2][now.second-1])
            {
                q.push({now.first+2, now.second-1});
                visited[now.first+2][now.second-1] = true;
            }

            if(now.first+2 < l && now.second+1 < l && !visited[now.first+2][now.second+1])
            {
                q.push({now.first+2, now.second+1});
                visited[now.first+2][now.second+1] = true;
            }

            if(now.first+1 < l && now.second+2 < l && !visited[now.first+1][now.second+2])
            {
                q.push({now.first+1, now.second+2});
                visited[now.first+1][now.second+2] = true;
            }

            q.pop();
        }

        level++;
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        bool visited[300][300] = {};
        queue<pair<int, int>> q;
        cin >> l;
        cin >> x0 >> y0;
        cin >> x >> y;
        cout << bfs(q, visited) << '\n';
    }

    return 0;
}
