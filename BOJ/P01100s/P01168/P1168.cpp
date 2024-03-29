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
        arr.resize(4194304);
        fill(arr.begin(), arr.end(), 0);
        leaf = 4194304/2;
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf); } //get sum of [L, R)
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
    {
        if(R <= nodeL || nodeR <= L) return 0;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid, nodeR);
    }

    void update(ll i, ll val)
    {
        i += leaf;
        arr[i] += val; //update part
        while(i > 1)
        {
            i /= 2;
            arr[i] = arr[i*2] + arr[i*2+1];
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = arr[i*2] + arr[i*2+1];
    }

    int kth(int node, int k)
    {
        if(node >= leaf) return node-leaf;
        int pivot = arr[node*2];
        if(k < pivot) return kth(node*2, k);
        else return kth(node*2+1, k-pivot);
    }
};

ll n, k, idx = 1;

int main()
{
    onlycc;
    cin >> n >> k;

    Segtree stree(n);
    for(int i = 0; i < n; i++) stree.arr[stree.leaf+i] = 1;
    stree.construct();

    cout << '<';
    for(int i = 0; i < n; i++)
    {
        int s = n-i;
        idx += (k-1);
        idx = (idx%s) ? idx%s : s;

        int temp = stree.kth(1, idx-1);
        stree.update(temp, -1);

        cout << temp+1;
        if(i != n-1) cout << ", ";
    }
    cout << '>';

    return 0;
}
