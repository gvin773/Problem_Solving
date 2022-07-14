#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string str;
set<string> s;

int main()
{
    onlycc;
    cin >> str;
    for(int i = 0; i < str.size(); i++) for(int j = 1; j <= str.size(); j++) s.insert(str.substr(i, j));
    cout << s.size();

    return 0;
}
