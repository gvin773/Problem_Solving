#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int t, n;
string a, b, str;

int main()
{
    onlycc;
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cin.ignore();
        getline(cin, a);
        getline(cin, b);
        getline(cin, str);

        vector<string> v1, v2, v3;
        int start = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == ' ')
            {
                v1.push_back(a.substr(start, i-start));
                start = i+1;
            }
        }
        v1.push_back(a.substr(start));

        start = 0;
        for(int i = 0; i < b.size(); i++)
        {
            if(b[i] == ' ')
            {
                v2.push_back(b.substr(start, i-start));
                start = i+1;
            }
        }
        v2.push_back(b.substr(start));

        start = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                v3.push_back(str.substr(start, i-start));
                start = i+1;
            }
        }
        v3.push_back(str.substr(start));

        int solve[1000] = {};
        for(int i = 0; i < v1.size(); i++)
        {
            solve[i] = find(v2.begin(), v2.end(), v1[i]) - v2.begin();
        }

        for(int i = 0; i < v3.size(); i++)
        {
            cout << v3[solve[i]] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
