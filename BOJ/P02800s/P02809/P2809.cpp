#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;


bool visited[300000];

class Trie
{
public:
    vector<pair<char, Trie*>> go;
    Trie *fail;
    bool output;
    int len;

    Trie()
    {
        output = false;
        len = 0;
    }

    void insert(const string &str, int idx)
    {
        if(idx == str.size())
        {
            output = true;
            len = str.size();
            return;
        }

        bool flag = true;
        auto next = str[idx];
        for(int i = 0; i < go.size(); i++)
        {
            if(go[i].first == next)
            {
                flag = false;
                go[i].second->insert(str, idx+1);
            }
        }
        if(flag)
        {
            go.push_back({next, new Trie});
            go.back().second->insert(str, idx+1);
        }
    }

    void find(const string &str)
    {
        auto now = this;
        for(int i = 0; i < str.size(); i++)
        {
            auto next = str[i];
            while(now != this)
            {
                bool flag = false;
                for(auto x : now->go) if(x.first == next) flag = true;
                if(flag) break;
                now = now->fail;
            }
            for(auto x : now->go)
            {
                if(x.first == next) now = x.second;
            }

            if(now->output)
            {
                for(int j = 0; j < now->len; j++) visited[i-j] = true;
            }
        }
    }
};

ll n, m, ans;
string s, x;
unordered_set<char> v;

int main()
{
    onlycc;
    Trie *root = new Trie;
    cin >> n >> s >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        for(auto c : x) v.insert(c);
        root->insert(x, 0);
    }

    root->fail = root;
    queue<Trie*> q;
    q.push(root);
    while(!q.empty())
    {
        auto now = q.front();
        q.pop();

        for(auto p : now->go)
        {
            auto next = p.second;
            if(next == nullptr) continue;

            if(now == root) next->fail = root;
            else
            {
                auto via = now->fail;
                while(via != root)
                {
                    bool flag = false;
                    for(auto viai : via->go) if(viai.first == p.first) flag = true;
                    if(flag) break;
                    via = via->fail;
                }
                for(auto viai : via->go)
                {
                    if(viai.first == p.first)
                    {
                        via = viai.second;
                        break;
                    }
                }
                next->fail = via;
            }

            if(next->fail->output)
            {
                next->output = true;
                next->len = max(next->len, next->fail->len);
            }
            q.push(next);
        }
    }

    root->find(s);
    for(int i = 0; i < n; i++) if(!visited[i]) ans++;
    cout << ans;

    return 0;
}
