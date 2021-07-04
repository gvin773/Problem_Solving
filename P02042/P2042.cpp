#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

class Segtree{
public:

    ll Size, leaf;
    vector<ll> arr;

    Segtree(int number) : Size(number)
    {
        leaf = 1;
        while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
        arr.resize(2*leaf);
        fill(arr.begin(), arr.end(), 0);
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf-1); } //get sum of [L, R]
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) //arr-indexing starts from 0, num-indexing may starts from 1(ex. sum(head-1, tail-1)
    {
        if(R < nodeL || nodeR < L) return 0;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
    }

    void update(ll i, ll val)
    {
        i += leaf;
        val -= arr[i];
        while(i > 0)
        {
            arr[i] += val;
            i /= 2;
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = arr[i*2] + arr[i*2+1];
    }
};

ll n, m, k, a, b, c;

int main()
{
    onlycc;
    cin >> n >> m >> k;

    Segtree stree(n);
    for(int i = 0; i < n; i++) cin >> stree.arr[stree.leaf+i];
    stree.construct();

    for(int i = 0; i < m+k; i++)
    {
        cin >> a >> b >> c;
        if(a == 1) stree.update(b-1, c);
        else cout << stree.sum(b-1, c-1) << '\n';
    }

    return 0;
}
