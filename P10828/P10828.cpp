#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n;
    string command;
    int x;
    stack<int> s;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        cin >> command;

        if(command == "pop")
        {
            if(s.empty())
                puts("-1");

            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }

        else if(command == "size")
            cout << s.size() << endl;

        else if(command == "empty")
            cout << s.empty() << endl;

        else if(command == "top")
        {
            if(s.empty())
                puts("-1");

            else
                cout << s.top() << endl;
        }

        else if(command == "push")
        {
            scanf("%d", &x);
            s.push(x);
        }
    }

    return 0;
}
