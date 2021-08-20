#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int t, n, m;

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        priority_queue<int> pq;
        queue<pair<int, int>> p;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            int data;
            cin >> data;
            pq.push(data);
            p.push(make_pair(i, data));
        }

        for(int cnt = 1; p.size();)
        {
            if(p.front().second == pq.top())
            {
                if(p.front().first == m+1) cout << cnt << '\n';
                cnt++;
                pq.pop();
                p.pop();
            }

            else
            {
                pair<int, int> temp;
                temp = p.front();
                p.pop();
                p.push(temp);
            }
        }
    }

    return 0;
}
