#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
bfs�� Ǯ�� �ȴ�. ������ �����ؾ��� ���� �湮�ߴ� ���� ��湮 �����ϴٴ� ���̴�.
���� visited�� �ʿ����� ���� ���� �ִٰ� ������ ���� �ִµ�, 13131���� 1��, 3���� �ٲٴ� ��
3�� 5���� �ٲٴ� ���� ��� 13131�̶�� ���� ����� ��´ٴ� ������, visited�� ������ TLE�� �߻�����
������ �� �ִ�. ���� level�� �����Ҷ����� visited�� ���� false�� �ʱ�ȭ ���ְ�, bfs�� �����Ѵ�.
*/

int n, k, m;
queue<int> q;

int change(int now, int i, int j)
{
    int d[10] = {}, cnt = 9;
    while(now)
    {
        d[cnt--] = now%10;
        now /= 10;
    }

    swap(d[i+cnt], d[j+cnt]);
    if(d[cnt+1] == 0) return -1;

    int ret = 0, x = 1;
    for(int re = 9; re > cnt; re--)
    {
        ret += d[re]*x;
        x *= 10;
    }

    return ret;
}

int bfs()
{
    q.push(n);

    int level = 0;
    while(!q.empty())
    {
        bool visited[1000001] = {};
        int Size = q.size();
        for(int s = 0; s < Size; s++)
        {
            if(level == k)
            {
                int ret = q.front();
                while(!q.empty())
                {
                    ret = max(ret, q.front());
                    q.pop();
                }
                return ret;
            }

            int now = q.front(), temp;
            q.pop();
            for(int i = 1; i <= m; i++)
            {
                for(int j = i+1; j <= m; j++)
                {
                    temp = change(now, i, j);
                    if(temp != -1 && !visited[temp])
                    {
                        visited[temp] = true;
                        q.push(temp);
                    }
                }
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
    m = to_string(n).size();
    cout << bfs();

    return 0;
}
