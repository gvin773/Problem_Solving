#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

class Segtree{
public:

    ll Size, leaf;
    vector<ll> arr;

    Segtree(int number) : Size(number)
    {
        leaf = 1;
        arr.resize(4*number);
        fill(arr.begin(), arr.end(), 0);
        while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf-1); } //get sum of [L, R]
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) //arr-indexing starts from 0, nodeNum-indexing may starts from 1 (ex. sum(head-1, tail-1))
    {
        if(R < nodeL || nodeR < L) return 0;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
    }

    ll msum(int L, int R) { return msum(L, R, 1, 0, leaf-1); } //get sum of [L, R]
    ll msum(int L, int R, int nodeNum, int nodeL, int nodeR) //arr-indexing starts from 0, nodeNum-indexing may starts from 1 (ex. sum(head-1, tail-1))
    {
        if(R < nodeL || nodeR < L) return LLONG_MAX;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return min(msum(L, R, nodeNum*2, nodeL, mid), msum(L, R, nodeNum*2+1, mid+1, nodeR));
    }
    ll Msum(int L, int R) { return Msum(L, R, 1, 0, leaf-1); } //get sum of [L, R]
    ll Msum(int L, int R, int nodeNum, int nodeL, int nodeR) //arr-indexing starts from 0, nodeNum-indexing may starts from 1 (ex. sum(head-1, tail-1))
    {
        if(R < nodeL || nodeR < L) return LLONG_MIN;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return max(Msum(L, R, nodeNum*2, nodeL, mid), Msum(L, R, nodeNum*2+1, mid+1, nodeR));
    }

    void update(ll i, ll val)
    {
        i += leaf;
        arr[i] = val;
        while(i > 1)
        {
            i /= 2;
            arr[i] += arr[i*2] + arr[i*2+1];
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = arr[i*2] + arr[i*2+1];
    }

    void minconstruct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = min(arr[i*2], arr[i*2+1]);
    }

    void maxconstruct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = max(arr[i*2], arr[i*2+1]);
    }
};

ll n, m, a, b;

int main()
{
    onlycc;
    cin >> n >> m;

    Segtree mintree(n), maxtree(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        mintree.arr[mintree.leaf+i] = a;
        maxtree.arr[maxtree.leaf+i] = a;
    }
    mintree.minconstruct();
    maxtree.maxconstruct();

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cout << mintree.msum(a-1, b-1) << ' ' << maxtree.Msum(a-1, b-1) << '\n';
    }

    return 0;
}
