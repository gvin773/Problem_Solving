#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 150;

class Trie
{
public:
    Trie *next[SIZE];
    int output;

    Trie()
    {
        fill(next, next+SIZE, nullptr);
        output = 0;
    }

    ~Trie()
    {
        for(int i = 0; i < SIZE; i++) if(next[i] != nullptr) delete next[i];
    }

    void add(const string &str, int idx)
    {
        if(str.size() == idx) output++;
        else
        {
            int nidx = str[idx] - ' ';
            if(next[nidx] == nullptr) next[nidx] = new Trie;

            next[nidx]->add(str, idx+1);
        }
    }

    ll counting(const string &str, int idx)
    {
        if(str.size() == idx) return output;
        return next[str[idx]-' ']->counting(str, idx+1);
    }
};

ll cnt;
string s;
vector<string> v;

int main()
{
    onlycc;
    Trie *root = new Trie;
    while(getline(cin, s))
    {
        v.push_back(s);
        root->add(s, 0);
        cnt++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto str : v)
    {
        cout.precision(4);
        cout << fixed << str << ' ' << root->counting(str, 0)*100 / (ld)cnt << '\n';
    }

    return 0;
}
