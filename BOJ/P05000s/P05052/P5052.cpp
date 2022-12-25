#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 10;

class Trie
{
public:
    Trie *next[SIZE];
    bool output, children;

    Trie()
    {
        fill(next, next+SIZE, nullptr);
        output = children = false;
    }

    ~Trie()
    {
        for(int i = 0; i < SIZE; i++) if(next[i] != nullptr) delete next[i];
    }

    void add(const string &str, int idx)
    {
        if(str.size() == idx) output = true;
        else
        {
            int nidx = str[idx] - '0';
            if(next[nidx] == nullptr) next[nidx] = new Trie;
            children = true;
            next[nidx]->add(str, idx+1);
        }
    }

    bool check()
    {
        if(output && children) return false;
        for(int i = 0; i < SIZE; i++) if(next[i] != nullptr && !next[i]->check()) return false;

        return true;
    }
};

ll tc, n;
string s;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        Trie *root = new Trie;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            root->add(s, 0);
        }

        cout << (root->check() ? "YES\n" : "NO\n");
        delete root;
    }

    return 0;
}
