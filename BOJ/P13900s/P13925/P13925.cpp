#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = 1e9+7;
const int Segtree_SIZE = 1<<18;
class Segtree{
public:

    ll Size, leaf;
    vector<ll> arr, lazy1, lazy2;

    Segtree(int number) : Size(number)
    {
        leaf = 1;
        arr.resize(Segtree_SIZE);
        lazy1.resize(Segtree_SIZE);
        lazy2.resize(Segtree_SIZE);
        fill(arr.begin(), arr.end(), 0);
        fill(lazy1.begin(), lazy1.end(), 1);
        fill(lazy2.begin(), lazy2.end(), 0);
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
        leaf = (Segtree_SIZE)/2;
    }

    void propagate(int nodeNum, int nodeL, int nodeR) //propagate [LL, RR)
    {
        if(lazy1[nodeNum] != 1 || lazy2[nodeNum] != 0)
        {
            if(nodeNum < leaf)
            {
                lazy1[nodeNum*2] = lazy1[nodeNum*2]*lazy1[nodeNum] % MOD;
                lazy1[nodeNum*2+1] = lazy1[nodeNum*2+1]*lazy1[nodeNum] % MOD;

                lazy2[nodeNum*2] = (lazy2[nodeNum*2]*lazy1[nodeNum]%MOD + lazy2[nodeNum]%MOD) % MOD;
                lazy2[nodeNum*2+1] = (lazy2[nodeNum*2+1]*lazy1[nodeNum]%MOD + lazy2[nodeNum]%MOD) % MOD;
            }

            arr[nodeNum] = (arr[nodeNum]*lazy1[nodeNum]%MOD + (nodeR-nodeL)*lazy2[nodeNum]%MOD) % MOD;
            lazy1[nodeNum] = 1;
            lazy2[nodeNum] = 0;
        }
    }

    void update(int L, int R, ll k, int order) { return update(L, R, k, 1, 0, leaf, order); } //add [L, R)
    void update(int L, int R, ll k, int nodeNum, int nodeL, int nodeR, int order)
    {
        propagate(nodeNum, nodeL, nodeR);
        if(R <= nodeL || nodeR <= L) return;
        if(L <= nodeL && nodeR <= R)
        {
            if(order == 1) lazy2[nodeNum] = (lazy2[nodeNum]+k) % MOD;
            if(order == 2)
            {
                lazy1[nodeNum] = lazy1[nodeNum]*k % MOD;
                lazy2[nodeNum] = lazy2[nodeNum]*k % MOD;
            }
            if(order == 3)
            {
                lazy1[nodeNum] = 0;
                lazy2[nodeNum] = k%MOD;
            }
            propagate(nodeNum, nodeL, nodeR);
            return;
        }

        ll mid = (nodeL + nodeR) / 2;
        update(L, R, k, nodeNum*2, nodeL, mid, order);
        update(L, R, k, nodeNum*2+1, mid, nodeR, order);

        arr[nodeNum] = (arr[nodeNum*2]%MOD + arr[nodeNum*2+1]%MOD) % MOD;
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf); } //get sum of [L, R)
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
    {
        propagate(nodeNum, nodeL, nodeR);
        if(R <= nodeL || nodeR <= L) return 0;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum]%MOD;
        ll mid = (nodeL + nodeR) / 2;
        return (sum(L, R, nodeNum*2, nodeL, mid)%MOD + sum(L, R, nodeNum*2+1, mid, nodeR)%MOD) % MOD;
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = (arr[i*2]%MOD + arr[i*2+1]%MOD) % MOD;
    }
};

ll n, m, o, x, y, v;

int main()
{
    onlycc;
    cin >> n;
    Segtree stree(n+1);
    for(int i = 0; i < n; i++) cin >> stree.arr[stree.leaf+i];
    stree.construct();

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> o >> x >> y;
        if(o != 4) cin >> v;
        if(o < 4) stree.update(x-1, y, v, o);
        else cout << stree.sum(x-1, y) << '\n';
    }

    return 0;
}
