#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

ll n, m, num[500000];
set<int> s;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> num[i];

    for(int i = 0; i < m; i++)
    {
        if(s.find(num[i]) == s.end()) cout << 0 << ' ';
        else cout << 1 << ' ';
    }

    return 0;
}
