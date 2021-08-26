#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int t, k;
string str;

int main()
{
    onlycc;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cin >> k >> str;
        vector<string> v;
        for(int i = 0; i < str.size(); i++)
            v.push_back(str.substr(i));

        sort(v.begin(), v.end());
        cout << '#' << tc << ' ' << (k-1 < v.size() ? v[k-1] : "none") << '\n';
    }

    return 0;
}
