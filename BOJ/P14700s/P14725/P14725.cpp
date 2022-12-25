#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

class Trie
{
public:
    map<string, Trie*> next;
    bool output, children;

    Trie()
    {
        output = children = false;
    }

    void add(const vector<string> &v, int idx)
    {
        if(v.size() == idx) output = true;
        else
        {
            auto str = v[idx];
            if(next.find(str) == next.end()) next[str] = new Trie;
            children = true;
            next[str]->add(v, idx+1);
        }
    }

    void print(int iter)
    {
        for(auto x : next)
        {
            for(int i = 0; i < iter; i++) cout << "--";
            cout << x.first << '\n';
            x.second->print(iter+1);
        }
    }
};

ll n, k;
string s;

int main()
{
    onlycc;
    Trie *root = new Trie;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        vector<string> v;
        for(int j = 0; j < k; j++)
        {
            cin >> s;
            v.push_back(s);
            root->add(v, 0);
        }
    }
    root->print(0);

    return 0;
}
