#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, p, root, d, ans;
vector<int> c[50];
bool deleted[50];

void dfs(int now)
{
    bool flag = true;
    for(int i : c[now])
    {
        if(!deleted[i])
        {
            flag = false;
            dfs(i);
        }
    }
    if(flag && !deleted[now]) ans++;
}

void Delete(int now)
{
    deleted[now] = true;
    for(int i : c[now]) Delete(i);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p;
        if(p != -1) c[p].push_back(i);
        else root = i;
    }
    cin >> d;
    Delete(d);
    if(!deleted[root]) dfs(root);

    cout << ans;

    return 0;
}
