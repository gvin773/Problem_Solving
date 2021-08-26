#define ALPHABETS_CNT 26
#define MAXN 1000000

struct Trie;
Trie* myAlloc();

struct Trie
{
    Trie* _children[ALPHABETS_CNT];
    bool fin;
    int len;

    void add(const char* word)
    {
        len++;
        if (*word != 0)
        {
            if (_children[*word - 'a'] == nullptr) _children[*word - 'a'] = myAlloc();
            _children[*word - 'a']->add(word + 1);
        }
        else fin = true;
    }

    int get(const char* word)
    {
        if (*word != 0)
        {
            if (_children[*word - 'a'] != nullptr) return _children[*word - 'a']->get(word + 1);
            return 0;
        }
        return len;
    }

    void clear()
    {
        fin = false;
        len = 0;
        for (int i = 0; i < ALPHABETS_CNT; i++)
            _children[i] = nullptr;
    }
};

Trie Node[MAXN];
int nodeCnt;
Trie* myAlloc()
{
    Trie* ret = &Node[nodeCnt++];
    ret->clear();
    return ret;
}

Trie* root;

void init(void)
{
    nodeCnt = 0;
    root = myAlloc();
}

void insert(int buffer_size, char *buf)
{
    root->add(buf);
}

int query(int buffer_size, char *buf)
{
	return root->get(buf);
}
