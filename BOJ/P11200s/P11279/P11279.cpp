#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x;
priority_queue<int> pq;

int main()
{
    onlycc;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x == 0)
        {
            cout << (pq.empty() ? 0 : pq.top()) << '\n';
            if(!pq.empty()) pq.pop();
        }
        else pq.push(x);
    }

    return 0;
}
