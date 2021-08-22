#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;
vector<int> v;

void track()
{
    if(v.size() == m)
    {
        for(int i : v) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        v.push_back(i);
        track();

        v.pop_back();
    }
}

int main()
{
    onlycc;
    cin >> n >> m;
    track();

    return 0;
}
