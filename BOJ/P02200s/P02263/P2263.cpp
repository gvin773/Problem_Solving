#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, in[100001], post[100001], idx[100001];

void f(int ins, int ine, int posts, int poste)
{
    if(ins > ine || posts > poste) return;


    int root = idx[post[poste]];
    cout << in[root] << ' ';

    f(ins, root-1, posts, posts + root-1-ins);
    f(root+1, ine, posts + root-ins, poste-1);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(int i = 1; i <= n; i++) cin >> post[i];
    f(1, n, 1, n);

    return 0;
}
