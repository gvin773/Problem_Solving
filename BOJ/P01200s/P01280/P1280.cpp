#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
#define MOD 1000000007
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
        arr.resize(524288);
        fill(arr.begin(), arr.end(), 0);
        leaf = 524288/2;
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf); } //get sum of [L, R]
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) //arr-indexing starts from 0, nodeNum-indexing may starts from 1 (ex. sum(head-1, tail-1))
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
};

ll n, x, ans = 1, M = 200000;

int main()
{
    onlycc;
    cin >> n;
    Segtree sumtree(n), cnttree(n);

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(i > 0) ans = ((cnttree.sum(0, x)*x - sumtree.sum(0, x) + sumtree.sum(x+1, M) - cnttree.sum(x+1, M)*x) % MOD) * ans % MOD;
        //if(i > 0) cout << "now: " << cnttree.sum(0, x)*x << ' ' << sumtree.sum(0, x) << ' ' << cnttree.sum(x+1, M)*x << ' ' << sumtree.sum(x+1, M) << ' ' << ans << '\n';
        cnttree.update(x, 1);
        sumtree.update(x, x);
    }
    cout << ans;

    return 0;
}
