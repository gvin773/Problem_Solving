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
        fill(arr.begin(), arr.end(), 0);
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
        leaf = 524288/2;
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
            arr[i] = arr[i*2] + arr[i*2+1];
    }
};

ll tc, n, m, x, pos[100010];

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;

        Segtree stree(n+m);
        for(int i = 0; i < n; i++) stree.arr[stree.leaf+i] = 1;
        stree.construct();
        for(int i = 1; i <= n; i++) pos[i] = n-i;

        ll cnt = 1, pre = -1;
        for(int i = 0; i < m; i++)
        {
            cin >> x;
            if(x == pre)
            {
                cout << 0 << ' ';
                continue;
            }
            pre = x;
            stree.update(pos[x], 0);
            cout << stree.sum(pos[x]+1, n+cnt) << ' ';
            pos[x] = n+cnt;
            stree.update(pos[x], 1);
            cnt++;
        }
        cout << '\n';
    }

    return 0;
}
