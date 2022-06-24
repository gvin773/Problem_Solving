#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, x;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x != 0) pq.push({abs(x), x});
        else if(pq.empty()) cout << 0 << '\n';
        else
        {
            cout << pq.top().second << '\n';
            pq.pop();
        }
    }

    return 0;
}
