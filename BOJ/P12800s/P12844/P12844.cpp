#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

class Segtree{
public:

    ll Size, leaf;
    vector<ll> arr, lazy;

    Segtree(int number) : Size(number)
    {
        leaf = 1;
        arr.resize(1<<21);
        lazy.resize(1<<21);
        fill(arr.begin(), arr.end(), 0);
        fill(lazy.begin(), lazy.end(), 0);
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
        leaf = (1<<21)/2;
    }

    void propagate(int nodeNum, int nodeL, int nodeR) //propagate [LL, RR)
    {
        if(lazy[nodeNum] != 0)
        {
            if(nodeNum < leaf)
            {
                lazy[nodeNum*2] ^= lazy[nodeNum];
                lazy[nodeNum*2+1] ^= lazy[nodeNum];
            }
            else arr[nodeNum] ^= (nodeR-nodeL)*lazy[nodeNum];
            lazy[nodeNum] = 0;
        }
    }

    void add(int L, int R, ll k) { return add(L, R, k, 1, 0, leaf); } //add [L, R)
    void add(int L, int R, ll k, int nodeNum, int nodeL, int nodeR)
    {
        propagate(nodeNum, nodeL, nodeR);
        if(R <= nodeL || nodeR <= L) return;
        if(L <= nodeL && nodeR <= R)
        {
            lazy[nodeNum] ^= k;
            propagate(nodeNum, nodeL, nodeR);
            return;
        }

        ll mid = (nodeL + nodeR) / 2;
        add(L, R, k, nodeNum*2, nodeL, mid);
        add(L, R, k, nodeNum*2+1, mid, nodeR);

        arr[nodeNum] = arr[nodeNum*2] ^ arr[nodeNum*2+1];
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf); } //get sum of [L, R)
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
    {
        propagate(nodeNum, nodeL, nodeR);
        if(R <= nodeL || nodeR <= L) return 0;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return sum(L, R, nodeNum*2, nodeL, mid) ^ sum(L, R, nodeNum*2+1, mid, nodeR);
    }

    void update(ll i, ll val)
    {
        i += leaf;
        arr[i] = val; //update part
        while(i > 1)
        {
            i /= 2;
            arr[i] = arr[i*2] + arr[i*2+1];
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = arr[i*2] ^ arr[i*2+1];
    }
};

ll n, m, a, b, c, d;

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
        cin >> a >> b >> c;
        if(a == 1)
        {
            cin >> d;
            stree.add(b, c+1, d);
        }
        else cout << stree.sum(b, c+1) << '\n';
    }

    return 0;
}
