#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

/*
bfs로 풀면 된다. 하지만 주의해야할 것은 방문했던 곳을 재방문 가능하다는 것이다.
따라서 visited가 필요하지 않을 수도 있다고 생각할 수도 있는데, 13131에서 1번, 3번을 바꾸는 것
3번 5번을 바꾸는 것이 모두 13131이라는 같은 결과를 얻는다는 점에서, visited가 없으면 TLE가 발생함을
유추할 수 있다. 따라서 level이 증가할때마다 visited를 전부 false로 초기화 해주고, bfs를 수행한다.
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
