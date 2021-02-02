#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;

/*
prev배열을 이용해서 지나온 경로를 저장한다.
L, R 연산시 string을 이용하는 방법은 시간적인 측면에서 손해를 보게 된다.
string은 꼭 필요한 상황이 아니면 지양하도록 하자.
*/

int t, a, b;

void bfs(bool visited[], pair<int, char> prev[], queue<int>& q)
{
    visited[a] = true;
    q.push(a);

    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            int now = q.front();
            if(now == b) return;
            q.pop();

            int D = 2*now % 10000;
            if(!visited[D])
            {
                visited[D] = true;
                q.push(D);
                prev[D] = make_pair(now, 'D');
            }

            int S = (now ? now-1 : 9999);
            if(!visited[S])
            {
                visited[S] = true;
                q.push(S);
                prev[S] = make_pair(now, 'S');
            }

            int d1 = (now%1000 == now ? 0 : now/1000);
            int d2 = (now%100 == now ? 0 : now%1000/100);
            int d3 = (now%10 == now ? 0 : now%100/10);
            int d4 = now%10;

            int L = d2*1000 + d3*100 + d4*10 + d1;
            if(!visited[L])
            {
                visited[L] = true;
                q.push(L);
                prev[L] = make_pair(now, 'L');
            }

            int R = d4*1000 + d1*100 + d2*10 + d3;
            if(!visited[R])
            {
                visited[R] = true;
                q.push(R);
                prev[R] = make_pair(now, 'R');
            }
        }
    }
}

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;
        bool visited[10000] = {};
        pair<int, char> prev[10000];
        queue<int> q;

        bfs(visited, prev, q);
        stack<char> s;
        for(int j = b; j != a; j = prev[j].first)
            s.push(prev[j].second);

        while(!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    }

    return 0;
}
