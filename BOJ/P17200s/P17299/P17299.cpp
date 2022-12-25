#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n, a[1000001], F[1000001], ans[1000001];
stack<ll> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        F[a[i]]++;
    }

    for(int i = n-1; i >= 0; i--)
    {
        while(!s.empty() && F[s.top()] <= F[a[i]]) s.pop();
        ans[i] = s.empty() ? -1 : s.top();
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';

    return 0;
}
