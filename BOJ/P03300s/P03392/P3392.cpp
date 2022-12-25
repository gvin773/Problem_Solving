#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

class Segtree{
public:

    ll Size, leaf;
    vector<ll> arr, num;

    Segtree(int number) : Size(number)
    {
        leaf = 1;
        arr.resize(1<<21);
        num.resize(1<<21);
        fill(arr.begin(), arr.end(), 0);
        fill(num.begin(), num.end(), 0);
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
        leaf = (1<<21)/4;
    }

    void add(int L, int R, ll k) { return add(L, R, k, 1, 0, leaf); } //add [L, R)
    void add(int L, int R, ll k, int nodeNum, int nodeL, int nodeR)
    {
        if(R <= nodeL || nodeR <= L) return;
        if(L <= nodeL && nodeR <= R) num[nodeNum] += k;
        else
        {
            ll mid = (nodeL + nodeR) / 2;
            add(L, R, k, nodeNum*2, nodeL, mid);
            add(L, R, k, nodeNum*2+1, mid, nodeR);
        }

        if(num[nodeNum]) arr[nodeNum] = nodeR-nodeL;
        else if(nodeL == nodeR) arr[nodeNum] = 0;
        else arr[nodeNum] = arr[nodeNum*2] + arr[nodeNum*2+1];
    }
};

ll n, a, b, c, d, ans;
pair<pii, pii> p[30000];

int main()
{
    onlycc;
    cin >> n;
    Segtree stree(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        p[i*2] = {{a, 1}, {b, d}}, p[i*2+1] = {{c, -1}, {b, d}};
    }
    sort(p, p+2*n);

    for(int i = 0; i < 2*n; i++)
    {
        int dist;
        if(i == 0) dist = 0;
        else dist = p[i].first.first - p[i-1].first.first;

        ans += stree.arr[1] * dist;
        stree.add(p[i].second.first, p[i].second.second, p[i].first.second);
    }
    cout << ans;

    return 0;
}
