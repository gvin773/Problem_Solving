#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> nodes[200001];
stack<int> ret;
queue<int> con;
int rumor[200001];
int n, m, time, num, check;
int temp[200001];

void BFS()
{
    while(!con.empty())
    {
        int now = con.front();
        con.pop();
        for(int i = 0; i < nodes[now].size(); i++)
        {
            int next = nodes[now][i];
            if(rumor[next] == -1)
            {
                int counter = 0;
                for(int j = 0; j < nodes[next].size(); j++)
                {
                    if(rumor[nodes[next][j]] != -1)
                        counter++;
                }

                if((float)counter >= nodes[next].size()/(float)2 && temp[next] == 0)
                {
                    temp[next] = time;
                    num++;
                    con.push(next);
                    ret.push(next);
                }
            }
        }

        check++;
        if(check == m)
        {
            for(int i = ret.top(); ret.top() != 0; i = ret.top())
            {
                //int next = nodes[now][i];
                rumor[i] = temp[i];
                temp[i] = 0;
                ret.pop();
            }

            check = 0;
            m = num;
            num = 0;
            time++;
        }

      /*  int k = 1;
        for(; k <= n; k++)
        {
            if(rumor[k] == -1)
                break;
        }

        if(k == n+1) break;*/

      /*  for(int i = 1; i <= n; i++)
            printf("%d ", rumor[i]);
            puts("");*/
    }
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        rumor[i] = -1;

    for(int i = 1; i <= n;)
    {
        int a;
        scanf("%d", &a);
        if(a)
        {
            nodes[i].push_back(a);
        }
        else i++;
    }

    scanf("%d", &m);
    for(int i = 1; i<= m; i++)
    {
        int a;
        scanf("%d", &a);
        rumor[a] = time;
        con.push(a);
    }

    time++;
    ret.push(0);
    BFS();

    for(int i = 1; i <= n; i++)
        printf("%d ", rumor[i]);

    return 0;
}
