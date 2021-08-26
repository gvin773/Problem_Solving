#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

class Tree
{
public:
    int N;
    vector<int> parent;
    vector<int> lc, rc;
    vector<char> alpha;
    vector<char> num;

    Tree(): N(0){}
    Tree(int n): N(n)
    {
        parent.resize(N, -1);
        lc.resize(N, -1);
        rc.resize(N, -1);
        alpha.resize(N);
    }

    void inorder(int root)
    {
        if(lc[root] != -1) inorder(lc[root]);
        num.push_back(alpha[root]);
        if(rc[root] != -1) inorder(rc[root]);
    }

    int get_ans()
    {
        for(int i = 1; i < N; i++)
        {
            if(lc[i] == -1 && rc[i] == -1) //leaf node
            {
                if(!('0' <= alpha[i] && alpha[i] <= '9')) return 0;
            }
            else if(lc[i] != -1 && rc[i] == -1) return 0;
            else if(lc[i] == -1 && rc[i] != -1) return 0;
            else
            {
                if('0' <= alpha[i] && alpha[i] <= '9') return 0;
            }
        }
        return 1;
    }
};

int n, x, L, R;
char c;

int main()
{
    onlycc;
    for(int tc = 1; tc <= 10; tc++)
    {
        cin >> n;

        Tree tree(n+1);
        for(int i = 0; i < n; i++)
        {
            cin >> x >> c;
            tree.alpha[x] = c;

            L = -1, R = -1;
            if(x*2 < n) cin >> L >> R;
            else if(x*2 == n) cin >> L;

            tree.lc[x] = L;
            tree.rc[x] = R;
            if(L != -1) tree.parent[L] = x;
            if(R != -1) tree.parent[R] = x;
        }

        cout << '#' << tc << ' ';
        tree.inorder(1);

        cout << tree.get_ans();
        cout << '\n';
    }

    return 0;
}
