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
    vector<pair<char, Trie*>> next;
    bool output, rm, save;

    Trie()
    {
        output = rm = save = false;
    }

    ~Trie()
    {
        for(auto x : next) delete x.second;
    }

    void add(const string &str, int idx, bool flag)
    {
        if(str.size() == idx) return;
        for(auto x : next)
        {
            if(x.first == str[idx])
            {
                if(flag) x.second->rm = true;
                else x.second->save = true;
                if(flag && idx+1 == str.size()) x.second->output = true;
                x.second->add(str, idx+1, flag);
                return;
            }
        }

        Trie *node = new Trie;
        next.push_back({str[idx], node});
        if(flag) node->rm = true;
        else node->save = true;
        if(flag && idx+1 == str.size()) node->output = true;
        node->add(str, idx+1, flag);
        next.shrink_to_fit();
    }

    ll counting(const string &str, int idx)
    {
        ll ret = 0;
        for(auto p : next)
        {
            if(p.second->rm)
            {
                if(!p.second->save) ret++;
                if(p.second->save && p.second->output) ret++;
                if(p.second->save) ret += p.second->counting(str, idx+1);
            }
        }

        return ret;
    }
};

ll tc, n1, n2;
string s;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        Trie *root = new Trie;
        cin >> n1;
        for(int i = 0; i < n1; i++)
        {
            cin >> s;
            root->add(s, 0, true);
        }
        cin >> n2;
        for(int i = 0; i < n2; i++)
        {
            cin >> s;
            root->add(s, 0, false);
        }
        if(n2 == 0)
        {
            cout << 1 << '\n';
            continue;
        }

        cout << root->counting(s, 0) << '\n';
        delete root;
    }

    return 0;
}
