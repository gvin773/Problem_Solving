#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, k;

class Fenwick
{
public:
    Fenwick(int n)
    {
        Tree.resize(n + 1);
        Tree[0] = 0;
        for (int i = 1; i <= n; i++)
            update(i, 1);
    }

    int sum(int Index)
    {
        int ret = 0;
        while (Index > 0)
        {
            ret += Tree[Index];
            Index -= (Index & -Index);
        }

        return ret;
    }

    void update(int Index, int num)
    {
        while (Index < Tree.size())
        {
            Tree[Index] += num;
            Index += (Index & -Index);
        }
    }

    vector<int> Tree;
};

int num_person(int i, int j, Fenwick &fenwick)
{
    j %= n;
    if(j == 0) j = n;
    if(j >= i) return fenwick.sum(j) - fenwick.sum(i);
    return fenwick.sum(n) - fenwick.sum(i) + fenwick.sum(j);
}

int main()
{
    onlycc;
    cin >> n >> k;

    Fenwick fenwick(n);
    cout << "<" << k;
    fenwick.update(k, -1);

    int cur = k;
    int left = n - 1;
    while(left > 0)
    {
        int L = cur + 1;
        int R = cur + n;
        while(L < R)
        {
            int mid = (L+R) / 2;
            int val = num_person(cur, mid, fenwick);
            int MOD = k % left;

            if(MOD == 0) MOD = left;
            if(val < MOD) L = mid + 1;
            else if(val == MOD) R = mid;
            else R = mid-1;
        }

        L %= n;
        if(L == 0) L = n;
        cout << ", " << L;

        cur = L;
        fenwick.update(L, -1);

        left--;
    }
    cout << ">";

    return 0;
}
