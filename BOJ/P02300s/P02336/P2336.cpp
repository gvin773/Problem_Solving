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
        fill(arr.begin(), arr.end(), LLONG_MAX);
        leaf = 4194304/2;
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf); } //get sum of [L, R)
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR)
    {
        if(R <= nodeL || nodeR <= L) return LLONG_MAX;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return min(sum(L, R, nodeNum*2, nodeL, mid), sum(L, R, nodeNum*2+1, mid, nodeR));
    }

    void update(ll i, ll val)
    {
        i += leaf;
        arr[i] = val; //update part
        while(i > 1)
        {
            i /= 2;
            arr[i] = min(arr[i*2], arr[i*2+1]);
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = min(arr[i*2], arr[i*2+1]);
    }

    int kth(int node, int k)
    {
        if(node >= leaf) return node-leaf;
        int pivot = arr[node*2];
        if(k < pivot) return kth(node*2, k);
        else return kth(node*2+1, k-pivot);
    }
};

ll n, x, ans;
pair<ll, pll> a[500001];

int main()
{
    onlycc;
    cin >> n;

    Segtree stree(n);
    for(int i = 0; i < n; i++) {cin >> x; a[x-1].first = i;}
    for(int i = 0; i < n; i++) {cin >> x; a[x-1].second.first = i;}
    for(int i = 0; i < n; i++) {cin >> x; a[x-1].second.second = i;}
    sort(a, a+n);

    for(int i = 0; i < n; i++)
    {
        if(stree.sum(0, a[i].second.second) > a[i].second.first) ans++;
        stree.update(a[i].second.second, a[i].second.first);
    }
    cout << ans;

    return 0;
}
