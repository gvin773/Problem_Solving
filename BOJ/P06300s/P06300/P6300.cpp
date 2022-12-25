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
    Trie *go[SIZE], *fail;
    vector<pii> v;

    Trie()
    {
        fill(go, go+SIZE, nullptr);
    }

    ~Trie()
    {
        for(int i = 0; i < SIZE; i++) if(go[i]) delete go[i];
    }

    void insert(const string &str, int idx, int widx)
    {
        if(idx == str.size())
        {
            v.push_back({widx, str.size()});
            return;
        }

        int next = str[idx] - 'A';
        if(go[next] == nullptr) go[next] = new Trie;
        go[next]->insert(str, idx+1, widx);
    }
};

ll l, c, w;
string arr[1000], x;
pll pos[1000];
char ans[1000];

int main()
{
    onlycc;
    cin >> l >> c >> w;

    Trie *root = new Trie;
    for(int i = 0; i < l; i++) cin >> arr[i];
    for(int i = 0; i < w; i++)
    {
        cin >> x;
        root->insert(x, 0, i);
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

            if(!next->fail->v.empty()) next->v.insert(next->v.end(), next->fail->v.begin(), next->fail->v.end());
            q.push(next);
        }
    }

    for(int i = 0, j = c-1; i < l && j >= 0; i < l-1 ? i++ : j--)
    {
        auto now = root;
        for(int k = 0; i-k >= 0 && j-k >= 0; k++)
        {
            int next = arr[i-k][j-k] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i-k+len-1, j-k+len-1};
                        ans[idx] = 'H';
                    }
                    else if(i-k+len-1 < pos[idx].first || (i-k+len-1 == pos[idx].first && j-k+len-1 <= pos[idx].second))
                    {
                        pos[idx] = {i-k+len-1, j-k+len-1};
                        ans[idx] = 'H';
                    }
                }
            }
        }
    }

    for(int i = 0; i < l; i++)
    {
        auto now = root;
        for(int j = c-1; j >= 0; j--)
        {
            int next = arr[i][j] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i, j+len-1};
                        ans[idx] = 'G';
                    }
                    else if(i < pos[idx].first || (i == pos[idx].first && j+len-1 <= pos[idx].second))
                    {
                        pos[idx] = {i, j+len-1};
                        ans[idx] = 'G';
                    }
                }
            }
        }
    }

    for(int i = 0, j = 0; i < l && j < c; j < c-1 ? j++ : i++)
    {
        auto now = root;
        for(int k = 0; i+k < l && j-k >= 0; k++)
        {
            int next = arr[i+k][j-k] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i+k-len+1, j-k+len-1};
                        ans[idx] = 'F';
                    }
                    else if(i+k-len+1 < pos[idx].first || (i+k-len+1 == pos[idx].first && j-k+len-1 <= pos[idx].second))
                    {
                        pos[idx] = {i+k-len+1, j-k+len-1};
                        ans[idx] = 'F';
                    }
                }
            }
        }
    }

    for(int j = 0; j < c; j++)
    {
        auto now = root;
        for(int i = 0; i < l; i++)
        {
            int next = arr[i][j] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i-len+1, j};
                        ans[idx] = 'E';
                    }
                    else if(i-len+1 < pos[idx].first || (i-len+1 == pos[idx].first && j <= pos[idx].second))
                    {
                        pos[idx] = {i-len+1, j};
                        ans[idx] = 'E';
                    }
                }
            }
        }
    }

    for(int i = 0, j = c-1; i < l && j >= 0; j > 0 ? j-- : i++)
    {
        auto now = root;
        for(int k = 0; i+k < l && j+k < c; k++)
        {
            int next = arr[i+k][j+k] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i+k-len+1, j+k-len+1};
                        ans[idx] = 'D';
                    }
                    else if(i+k-len+1 < pos[idx].first || (i+k-len+1 == pos[idx].first && j+k-len+1 <= pos[idx].second))
                    {
                        pos[idx] = {i+k-len+1, j+k-len+1};
                        ans[idx] = 'D';
                    }
                }
            }
        }
    }

    for(int i = 0; i < l; i++)
    {
        auto now = root;
        for(int j = 0; j < c; j++)
        {
            int next = arr[i][j] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i, j-len+1};
                        ans[idx] = 'C';
                    }
                    else if(i < pos[idx].first || (i == pos[idx].first && j-len+1 <= pos[idx].second))
                    {
                        pos[idx] = {i, j-len+1};
                        ans[idx] = 'C';
                    }
                }
            }
        }
    }

    for(int i = 0, j = 0; i < l && j < c; i < l-1 ? i++ : j++)
    {
        auto now = root;
        for(int k = 0; i-k >= 0 && j+k < c; k++)
        {
            int next = arr[i-k][j+k] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i-k+len-1, j+k-len+1};
                        ans[idx] = 'B';
                    }
                    else if(i-k+len-1 < pos[idx].first || (i-k+len-1 == pos[idx].first && j+k-len+1 <= pos[idx].second))
                    {
                        pos[idx] = {i-k+len-1, j+k-len+1};
                        ans[idx] = 'B';
                    }
                }
            }
        }
    }

    for(int j = 0; j < c; j++)
    {
        auto now = root;
        for(int i = l-1; i >= 0; i--)
        {
            int next = arr[i][j] - 'A';
            while(now != root && now->go[next] == nullptr) now = now->fail;
            if(now->go[next] != nullptr) now = now->go[next];

            if(!now->v.empty())
            {
                for(auto z : now->v)
                {
                    int idx = z.first, len = z.second;
                    if(!ans[idx])
                    {
                        pos[idx] = {i+len-1, j};
                        ans[idx] = 'A';
                    }
                    else if(i+len-1 < pos[idx].first || (i+len-1 == pos[idx].first && j <= pos[idx].second))
                    {
                        pos[idx] = {i+len-1, j};
                        ans[idx] = 'A';
                    }
                }
            }
        }
    }

    for(int i = 0; i < w; i++) cout << pos[i].first << ' ' << pos[i].second << ' ' << ans[i] << '\n';

    return 0;
}
