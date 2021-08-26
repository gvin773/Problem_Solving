#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll t, n, a[10], k;

ll get_ans()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, k});

    while(pq.top().second)
    {
        pii now = pq.top();
        pq.pop();

        pq.push({now.first + now.second, 0});
        for(int i = 0; i < n; i++)
            pq.push({now.first + now.second%a[i], now.second/a[i]});
    }

    return pq.top().first;
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        cout << '#' << tc << ' ' << get_ans() << '\n';
    }

    return 0;
}
