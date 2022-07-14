#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, a[123457], p;
char t;
vector<int> c[123457];

ll dfs(int now)
{
    for(auto &next : c[now])
    {
        a[now] += dfs(next);
    }

    return a[now] < 0 ? 0 : a[now];
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        cin >> t >> a[i] >> p;
        if(t == 'W') a[i] *= (-1);
        c[p].push_back(i);
    }

    dfs(1);
    cout << a[1];

    return 0;
}
