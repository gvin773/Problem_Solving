#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

int n, x;
string command;
queue<int> q;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> command;

        if(command == "pop")
        {
            if(q.empty()) cout << "-1\n";
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }

        else if(command == "size") cout << q.size() << '\n';
        else if(command == "empty") cout << q.empty() << '\n';

        else if(command == "front")
        {
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        }

        else if(command == "back")
        {
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }

        else if(command == "push")
        {
            cin >> x;
            q.push(x);
        }
    }

    return 0;
}
