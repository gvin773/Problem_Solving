#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<pair<int, string>> p;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int len = str.size();
        p.push_back(pair<int, string>(len, str));
    }

    sort(p.begin(), p.end());

    for(vector<pair<int, string>> ::iterator iter = p.begin(); iter != p.end(); iter++)
    {
        if(iter == p.begin()) cout << iter->second << endl;
        if(iter != p.begin() && iter->second != (iter-1)->second)
            cout << iter->second << endl;
    }
}
