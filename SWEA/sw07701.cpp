#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int t, n;
string str;

bool compare(string i, string j)
{
    if(i.size() == j.size()) return i < j;
    else return i.size() < j.size();
}

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        vector<string> v;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end(), compare);
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << '#' << tc << '\n';
        for(auto i : v) cout << i << '\n';
    }

    return 0;
}
