#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const ll MOD = 1000000007;

ll dp[30];

ll factorial(ll x)
{
    if(dp[x] != -1) return dp[x];
    return dp[x] = (x%MOD) * (factorial(x-1)%MOD) % MOD;
}

class Trie
{
public:
    vector<pair<char, Trie*>> next;
    int children;

    Trie()
    {
        children = 0;
    }

    void add(const string &str, int idx)
    {
        if(str.size() == idx) children++;
        else
        {
            for(auto x : next)
            {
                if(x.first == str[idx])
                {
                    x.second->add(str, idx+1);
                    return;
                }
            }

            Trie *node = new Trie;
            next.push_back({str[idx], node});
            node->add(str, idx+1);
            next.shrink_to_fit();
            children++;
        }
    }

    ll counting(const string &str, int idx)
    {
        ll ret = factorial(children);
        for(auto x : next) ret = (ret%MOD) * (x.second->counting(str, idx+1)%MOD) % MOD;

        return ret;
    }
};

ll n;
string s;

int main()
{
    onlycc;
    Trie *root = new Trie;
    memset(dp, -1, sizeof(dp));
    dp[0] = 1, dp[1] = 1;

    cin >> n;
    while(n--)
    {
        cin >> s;
        root->add(s, 0);
    }
    cout << root->counting(s, 0) % MOD;

    return 0;
}
