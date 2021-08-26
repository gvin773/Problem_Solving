#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int t, n, q, x;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        priority_queue<int> pq;
        cin >> n;
        cout << '#' << tc << ' ';
        for(int i = 0; i < n; i++)
        {
            cin >> q;
            if(q == 1)
            {
                cin >> x;
                pq.push(x);
            }
            else
            {
                if(pq.empty()) cout << -1 << ' ';
                else
                {
                    cout << pq.top() << ' ';
                    pq.pop();
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
