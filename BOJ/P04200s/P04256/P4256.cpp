#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t, n, in[100001], pre[100001], idx[100001];

void f(int ins, int ine, int pres, int pree)
{
    if(ins > ine || pres > pree) return;

    int root = idx[pre[pres]];
    f(ins, root-1, pres+1, pres+1 + root-1-ins);
    f(root+1, ine, pres+1 + root-ins, pree);

    cout << in[root] << ' ';
}

int main()
{
    onlycc;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> pre[i];
        for(int i = 1; i <= n; i++)
        {
            cin >> in[i];
            idx[in[i]] = i;
        }
        f(1, n, 1, n);
        cout << '\n';
    }

    return 0;
}
