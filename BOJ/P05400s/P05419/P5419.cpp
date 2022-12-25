#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

class Segtree{
public:

    ll Size, leaf;
    vector<ll> arr;

    Segtree(int number) : Size(number)
    {
        leaf = 1;
        arr.resize(1<<21);
        fill(arr.begin(), arr.end(), 0);
        //while(leaf < Size) leaf *= 2; //[leaf, 2leaf): leaf nodes
        leaf = (1<<21)/2;
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
};

bool cmpy(const pii &a, const pii &b)
{
    return a.second < b.second;
}

bool cmp(const pii &a, const pii &b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

ll tc, n, x, y, ans;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        Segtree stree(n+1);
        pii point[80000];
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            point[i] = {x, y};
        }
        sort(point, point+n, cmpy);

        ll idx = 0, y[80000];
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && point[i].second != point[i-1].second) idx++;
            y[i] = idx;
        }
        for(int i = 0; i < n; i++) point[i].second = y[i];
        sort(point, point+n, cmp);

        ans = 0;
        int M = point[0].second+1;
        for(int i = 0; i < n; i++)
        {
            ans += stree.sum(point[i].second, M);
            M = max(M, point[i].second+1);
            stree.update(point[i].second, 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
