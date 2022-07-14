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
        return max(sum(L, R, nodeNum*2, nodeL, mid), sum(L, R, nodeNum*2+1, mid+1, nodeR));
    }

    void update(ll i, ll val)
    {
        i += leaf;
        arr[i] = val; //update part
        while(i > 1)
        {
            i /= 2;
            arr[i] = max(arr[i*2], arr[i*2+1]);
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = arr[i*2] + arr[i*2+1];
    }
};

ll n, a;

bool cmp(pll a, pll b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    onlycc;
    cin >> n;
    Segtree stree(n);
    vector<pll> v;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto x : v)
    {
        int s = stree.sum(0, x.second);
        stree.update(x.second, s+1);
    }
    cout << n - stree.sum(0, n-1) << '\n';

    return 0;
}
