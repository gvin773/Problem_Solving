#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

/*
가능한 퍼즐의 상태가 연결된 그래프로 볼 수 있다.
bfs를 이용하여 탐색해주고, 각 퍼즐의 상태는 string으로 만들어 준다.
visited를 배열로 만들 방법이 없으므로 set을 이용하여 체크해준다.
*/

int num[9];
string start;
set<string> visited;
queue<string> q;

void check(const string &next)
{
    if(visited.find(next) == visited.end())
    {
        q.push(next);
        visited.insert(next);
    }
}

int bfs()
{
    visited.insert(start);
    q.push(start);

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            string now = q.front();
            if(now == "123456780") return level;
            q.pop();

            string next = now;

            if(now[0] == '0')
            {
                swap(next[0], next[1]);
                check(next);

                next = now;
                swap(next[0], next[3]);
                check(next);
            }

            else if(now[2] == '0')
            {
                swap(next[2], next[1]);
                check(next);

                next = now;
                swap(next[2], next[5]);
                check(next);
            }

            else if(now[6] == '0')
            {
                swap(next[6], next[7]);
                check(next);

                next = now;
                swap(next[6], next[3]);
                check(next);
            }

            else if(now[8] == '0')
            {
                swap(next[8], next[7]);
                check(next);

                next = now;
                swap(next[8], next[5]);
                check(next);
            }

            else if(now[1] == '0')
            {
                swap(next[1], next[0]);
                check(next);

                next = now;
                swap(next[1], next[2]);
                check(next);

                next = now;
                swap(next[1], next[4]);
                check(next);
            }

            else if(now[7] == '0')
            {
                swap(next[7], next[6]);
                check(next);

                next = now;
                swap(next[7], next[8]);
                check(next);

                next = now;
                swap(next[7], next[4]);
                check(next);
            }

            else if(now[3] == '0')
            {
                swap(next[3], next[0]);
                check(next);

                next = now;
                swap(next[3], next[6]);
                check(next);

                next = now;
                swap(next[3], next[4]);
                check(next);
            }

            else if(now[5] == '0')
            {
                swap(next[5], next[2]);
                check(next);

                next = now;
                swap(next[5], next[8]);
                check(next);

                next = now;
                swap(next[5], next[4]);
                check(next);
            }

            else
            {
                swap(next[4], next[1]);
                check(next);

                next = now;
                swap(next[4], next[7]);
                check(next);

                next = now;
                swap(next[4], next[3]);
                check(next);

                next = now;
                swap(next[4], next[5]);
                check(next);
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    onlycc;
    for(int i = 0; i < 9; i++) cin >> num[i];
    for(int i = 0; i < 9; i++) start += to_string(num[i]);
    cout << bfs();

    return 0;
}
