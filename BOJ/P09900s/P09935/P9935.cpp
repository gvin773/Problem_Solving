#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string a, b;
vector<char> c;

int main()
{
    onlycc;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i]);
        if(c.size() >= b.size())
        {
            for(int i = 0; i < b.size(); i++) if(b[b.size()-1-i] != c[c.size()-1-i]) goto xy;
            for(int i = 0; i < b.size(); i++) c.pop_back();
        }
        xy:;
    }
    if(c.empty()) cout << "FRULA";
    else for(auto x: c) cout << x;

    return 0;
}

