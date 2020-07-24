#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> nodes[1001];
bool checkBFS[1001], checkDFS[1001];

void DFS(int n, int m, int v)
{
    stack<int> list;
    list.push(v);

    while(list.size())
    {
        int now = list.top();
        list.pop();
        if(!checkDFS[now])
        {
            checkDFS[now] = true;
            for(int i = nodes[now].size()-1; i >= 0; i--)
            {
                int next = nodes[now][i];
                if(!checkDFS[next])
                    list.push(next);
            }

            printf("%d ", now);
        }
    }
}

void BFS(int n, int m, int v)
{
    queue<int> list;
    list.push(v);
    checkBFS[v] = true;

    while(!list.empty())
    {
        int now = list.front();
        list.pop();
        for(int i = 0; i < nodes[now].size(); i++)
        {
            int next = nodes[now][i];
            if(!checkBFS[next])
            {
                list.push(next);
                checkBFS[next] = true;
            }
        }

        printf("%d ", now);
    }
}

int main()
{
    int n, m, v;
    scanf("%d%d%d", &n, &m, &v);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    for(int i = 1; i <= 1000; i++)
        if(nodes[i].size() >= 2)
            sort(nodes[i].begin(), nodes[i].end());

    DFS(n, m, v);
    puts("");
    BFS(n, m, v);

    return 0;
}
