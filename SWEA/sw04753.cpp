#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#define ALPHABETS_CNT 26
#define MAXN 30000
using namespace std;

typedef long long ll;

struct Trie;
Trie* myAlloc();

struct Trie
{
    Trie* _children[ALPHABETS_CNT];
    int cnt, num;

    void add(const char* word, int temp)
    {
        cnt++;
        temp += cnt;
        if(*word != 0)
        {
            if(_children[*word - 'a'] == nullptr) _children[*word - 'a'] = myAlloc();
            _children[*word - 'a']->add(word + 1, temp);
        }
        else num = temp;
    }

    int get(const char* word)
    {
        Trie* now = this;
        int comp = 0;
        bool flag = false;

        for(int i = 0; word[i]; i++)
        {
            comp += now->cnt;
            if(!now->_children[word[i] - 'a'])
            {
                flag = true;
                break;
            }
            now = now->_children[word[i] - 'a'];
        }
        if(flag) return comp;
        if(now->num == -1) return comp + now->cnt;
        return now->num;
    }

    void clear()
    {
        cnt = 0, num = -1;
        for(int i = 0; i < ALPHABETS_CNT; i++) _children[i] = nullptr;
    }
};

Trie Node[MAXN*30];
int nodeCnt = 0;
Trie* myAlloc()
{
    Trie* ret = &Node[nodeCnt++];
    ret->clear();
    return ret;
}

ll t, n, m, ans;
string w, target;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        nodeCnt = 0;
        Trie* root = myAlloc();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> w;
            root->add(w.c_str(), 0);
        }

        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> target;
            ans += root->get(target.c_str());
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
