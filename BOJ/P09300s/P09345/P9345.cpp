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
        arr.resize(524288);
        if(number) fill(arr.begin(), arr.end(), LLONG_MIN);
        else fill(arr.begin(), arr.end(), LLONG_MAX);
        leaf = 524288/2;
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
    }

    ll msum(int L, int R) { return msum(L, R, 1, 0, leaf); } //get sum of [L, R)
    ll msum(int L, int R, int nodeNum, int nodeL, int nodeR)
    {
        if(R <= nodeL || nodeR <= L) return LLONG_MAX;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return min(msum(L, R, nodeNum*2, nodeL, mid), msum(L, R, nodeNum*2+1, mid, nodeR));
    }

    ll Msum(int L, int R) { return Msum(L, R, 1, 0, leaf); } //get sum of [L, R)
    ll Msum(int L, int R, int nodeNum, int nodeL, int nodeR)
    {
        if(R <= nodeL || nodeR <= L) return LLONG_MIN;
        if(L <= nodeL && nodeR <= R) return arr[nodeNum];
        ll mid = (nodeL + nodeR) / 2;
        return max(Msum(L, R, nodeNum*2, nodeL, mid), Msum(L, R, nodeNum*2+1, mid, nodeR));
    }

    void mupdate(ll i, ll val)
    {
        i += leaf;
        arr[i] = val; //update part
        while(i > 1)
        {
            i /= 2;
            arr[i] = min(arr[i*2], arr[i*2+1]);
        }
    }
    void Mupdate(ll i, ll val)
    {
        i += leaf;
        arr[i] = val; //update part
        while(i > 1)
        {
            i /= 2;
            arr[i] = max(arr[i*2], arr[i*2+1]);
        }
    }

    void mconstruct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = min(arr[i*2], arr[i*2+1]);
    }
    void Mconstruct()
    {
        for(ll i = leaf-1; i > 0; i--)
            arr[i] = max(arr[i*2], arr[i*2+1]);
    }
};

ll tc, n, k, q, a, b;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;

        Segtree mintree(0), maxtree(1);
        for(int i = 0; i < n; i++)
        {
            mintree.arr[mintree.leaf+i] = i;
            maxtree.arr[maxtree.leaf+i] = i;
        }
        mintree.mconstruct();
        maxtree.Mconstruct();

        for(int i = 0; i < k; i++)
        {
            cin >> q >> a >> b;
            if(q)
            {
                if(maxtree.Msum(a, b+1) == b && mintree.msum(a, b+1) == a) cout << "YES\n";
                else cout << "NO\n";
            }
            else
            {
                int sa = mintree.arr[mintree.leaf+a], sb = maxtree.arr[mintree.leaf+b];
                mintree.mupdate(a, sb);
                mintree.mupdate(b, sa);
                maxtree.Mupdate(a, sb);
                maxtree.Mupdate(b, sa);
            }
        }
    }

    return 0;
}
