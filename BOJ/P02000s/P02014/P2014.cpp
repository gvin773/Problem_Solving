#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll k, n, a[100], cnt, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    onlycc;
    cin >> k >> n;
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }

    while(1)
    {
        ll m = pq.top();
        if(++cnt == n)
        {
            ans = m;
            break;
        }

        for(int i = 0; i < k; i++) if(m*a[i] < (1LL<<31)) pq.push(m * a[i]);
        while(!pq.empty() && m == pq.top()) pq.pop();
    }
    cout << ans;

    return 0;
}
