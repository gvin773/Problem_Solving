#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, x, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    if(n == 1)
    {
        cout << 0;
        return 0;
    }

    while(pq.size() != 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        ans += (a+b);
        pq.push(a+b);
    }
    cout << ans;

    return 0;
}
