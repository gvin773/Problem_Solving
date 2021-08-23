#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

typedef long long ll;

list<char> str;

int main()
{
    onlycc;
    string temp;
    cin >> temp;

    for(int i = 0; i < temp.size(); i++)
        str.push_back(temp[i]);

    auto iter = str.end();

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        char command;
        cin >> command;

        if(command == 'L' && iter != str.begin())
        {
            iter--;
        }

        else if(command == 'D' && iter != str.end())
        {
            iter++;
        }

        else if(command == 'B' && iter != str.begin())
        {
            if(iter == str.end()) iter++ = str.erase(--iter);
            else iter++ = str.erase(--iter);
        }

        else if(command == 'P')
        {
            char c;
            cin >> c;
            str.insert(iter, c);
        }
    }

    for(auto iter = str.begin(); iter != str.end(); iter++)
        cout << *iter;

    return 0;
}
