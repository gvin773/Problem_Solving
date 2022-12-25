#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

const int SIZE = 4;

ll ans;

class Trie
{
public:
    Trie *go[SIZE], *fail;
    int output;

    Trie()
    {
        fill(go, go+SIZE, nullptr);
        output = 0;
    }

    ~Trie()
    {
        for(int i = 0; i < SIZE; i++) if(go[i]) delete go[i];
    }

    void insert(const string &str, int idx)
    {
        if(idx == str.size())
        {
            output = 1;
            return;
        }

        char x;
        if(str[idx] == 'A') x = 'a';
        else if(str[idx] == 'T') x = 'b';
        else if(str[idx] == 'G') x = 'c';
        else x = 'd';

        int next = x - 'a';
        if(go[next] == nullptr) go[next] = new Trie;
        go[next]->insert(str, idx+1);
    }

    void find(const string &str)
    {
        auto now = this;
        for(int i = 0; i < str.size(); i++)
        {
            char x;
            if(str[i] == 'A') x = 'a';
            else if(str[i] == 'T') x = 'b';
            else if(str[i] == 'G') x = 'c';
            else x = 'd';

            int next = x - 'a';
            while(now != this && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            ans += now->output;
        }
    }
};

ll tc, n, m;
string dna, marker;

int main()
{
    onlycc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> dna >> marker;
        Trie *root = new Trie;
        root->insert(marker, 0);
        for(int i = 0; i < m; i++)
        {
            for(int len = 2; i+len <= m; len++)
            {
                string rev = marker.substr(i, len);
                reverse(rev.begin(), rev.end());
                string temp = marker.substr(0, i) + rev + marker.substr(i+len);
                root->insert(temp, 0);
            }
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
        root->find(dna);
        cout << ans << '\n';

        delete root;
    }

    return 0;
}
