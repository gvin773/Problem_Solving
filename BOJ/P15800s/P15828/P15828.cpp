#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, x;
queue<ll> q;

int main()
{
    onlycc;
    cin >> n;
    while(1)
    {
        cin >> x;
        if(x == -1) break;
        if(x && q.size() < n) q.push(x);
        else if(!x && !q.empty()) q.pop();
    }
    if(q.empty()) cout << "empty";
    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}
