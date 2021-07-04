#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MOD 1000000007
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
        fill(arr.begin(), arr.end(), 1);
    }

    ll sum(int L, int R) { return sum(L, R, 1, 0, leaf-1); } //get sum of [L, R]
    ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) //arr-indexing starts from 0, num-indexing may starts from 1(ex. sum(head-1, tail-1)
    {
        if(R < nodeL | nodeR < L) return 1;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return (sum(L, R, nodeNum*2, nodeL, mid) % MOD) * (sum(L, R, nodeNum*2+1, mid+1, nodeR) % MOD) % MOD;
    }

    void update(ll i, ll val)
    {
        i += leaf;
        arr[i] = val;
        while(i > 1)
        {
            i /= 2;
            arr[i] = (arr[i*2] * arr[i*2+1]) % MOD;
        }
    }

    void construct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = (arr[i*2] * arr[i*2+1]) % MOD;
    }
};

ll n, m, k, a, b, c;

int main()
{
    onlycc;
    cin >> n >> m >> k;
    Segtree st(n);
    for(int i = 0; i < n; i++) cin >> st.arr[st.leaf+i];
    st.construct();
    for(int i = 0; i < m+k; i++)
    {
        cin >> a >> b >> c;
        if(a == 1) st.update(b-1, c);
        else cout << st.sum(b-1, c-1) << '\n';
    }

    return 0;
}
