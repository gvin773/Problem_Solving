#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 30;

class Trie
{
public:
    Trie *next[SIZE];
    bool root;
    int children, word;

    Trie()
    {
        fill(next, next+SIZE, nullptr);
        root = false;
        children = word = 0;
    }

    ~Trie()
    {
        for(int i = 0; i < SIZE; i++) if(next[i] != nullptr) delete next[i];
    }

    void add(const string &str, int idx)
    {
        if(str.size() == idx) children++;
        else
        {
            int nidx = str[idx] - 'a';
            if(next[nidx] == nullptr)
            {
                next[nidx] = new Trie;
                children++;
            }

            next[nidx]->add(str, idx+1);
            word++;
        }
    }

    ll counting()
    {
        ll ret = 0;
        if(root || children >= 2) ret = word;
        for(int i = 'a'; i <= 'z'; i++) if(next[i-'a'] != nullptr) ret += next[i-'a']->counting();

        return ret;
    }
};

ll n;
string s;

int main()
{
    onlycc;
    while(cin >> n)
    {
        Trie *root = new Trie;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            root->add(s, 0);
        }
        root->root = true;

        cout.precision(2);
        cout << fixed << root->counting() / (ld)n << '\n';
        delete root;
    }

    return 0;
}
