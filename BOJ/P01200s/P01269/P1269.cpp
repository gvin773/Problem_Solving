#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m, x, ans;
set<int> a, b;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        b.insert(x);
    }
    for(auto i : a) if(b.find(i) == b.end()) ans++;
    for(auto i : b) if(a.find(i) == a.end()) ans++;
    cout << ans;

    return 0;
}
