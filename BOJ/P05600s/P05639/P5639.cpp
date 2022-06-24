#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x, node[10000], cnt;

void solve(int s, int e)
{
    if(s >= e) return;

    int t = s+1;
    while(t < e && node[s] > node[t]) t++;

    solve(s+1, t);
    solve(t, e);
    cout << node[s] << '\n';
}

int main()
{
    onlycc;
    while(cin >> x) node[cnt++] = x;
    solve(0, cnt);

    return 0;
}
