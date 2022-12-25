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
    Trie *go[26], *fail;
    bool output;

    Trie()
    {
        fill(go, go+26, nullptr);
        output = false;
    }

    ~Trie()
    {
        for(int i = 0; i < 26; i++) if(go[i]) delete go[i];
    }

    void insert(const string &str, int idx)
    {
        if(idx == str.size())
        {
            output = true;
            return;
        }

        int next = str[idx] - 'a';
        if(go[next] == nullptr) go[next] = new Trie;
        go[next]->insert(str, idx+1);
    }

    bool find(const string &str)
    {
        auto now = this;
        for(int i = 0; i < str.size(); i++)
        {
            int next = str[i] - 'a';
            while(now != this && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(now->output) return true;
        }

        return false;
    }
};

ll n, Q;
string s;

int main()
{
    onlycc;
    Trie *root = new Trie;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        root->insert(s, 0);
    }

    root->fail = root;
    queue<Trie*> q;
    q.push(root);
    while(!q.empty())
    {
        auto now = q.front();
        q.pop();

        for(int i = 0; i < 26; i++)
        {
            auto next = now->go[i];
            if(next == nullptr) continue;

            if(now == root) next->fail = root;
            else
            {
                auto via = now->fail;
                while(via != root && via->go[i] == nullptr) via = via->fail;
                if(via->go[i] != nullptr) via = via->go[i];
                next->fail = via;
            }

            if(next->fail->output) next->output = true;
            q.push(next);
        }
    }

    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> s;

        if(root->find(s)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
