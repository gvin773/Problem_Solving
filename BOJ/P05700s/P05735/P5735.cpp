#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 128;

ll ans;

class Trie
{
public:
    Trie *go[SIZE], *fail;
    bool output;

    Trie()
    {
        fill(go, go+SIZE, nullptr);
        output = false;
    }

    ~Trie()
    {
        for(int i = 0; i < SIZE; i++) if(go[i]) delete go[i];
    }

    void insert(const string &str, int idx)
    {
        if(idx == str.size())
        {
            output = true;
            return;
        }

        int next = str[idx];
        if(go[next] == nullptr) go[next] = new Trie;
        go[next]->insert(str, idx+1);
    }

    int find(const string &str, int j)
    {
        auto now = this;
        for(int i = j; i < str.size(); i++)
        {
            int next = str[i];
            while(now != this && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(now->output)
            {
                ans++;
                return i+1;
            }
        }

        return -1;
    }
};

ll n, m;
string x;

int main()
{
    onlycc;
    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        Trie *root = new Trie;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            root->insert(x, 0);
        }

        root->fail = root;
        queue<Trie*> q;
        q.push(root);
        while(!q.empty())
        {
            auto now = q.front();
            q.pop();

            for(int i = 0; i < SIZE; i++)
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

                next->output += next->fail->output;
                q.push(next);
            }
        }

        ans = 0;
        cin.ignore();
        for(int i = 0; i < m; i++)
        {
            getline(cin, x);
            int j = 0;
            while(j < x.size() && j != -1) j = root->find(x, j);
        }
        cout << ans << '\n';

        delete root;
    }

    return 0;
}
