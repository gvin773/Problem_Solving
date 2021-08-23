#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int n;
    string command;
    int x;
    queue<int> q;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        cin >> command;

        if(command == "pop")
        {
            if(q.empty())
                puts("-1");

            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }

        else if(command == "size")
            cout << q.size() << endl;

        else if(command == "empty")
            cout << q.empty() << endl;

        else if(command == "front")
        {
            if(q.empty())
                puts("-1");

            else
                cout << q.front() << endl;
        }

        else if(command == "back")
        {
            if(q.empty())
                puts("-1");

            else
                cout << q.back() << endl;
        }

        else if(command == "push")
        {
            scanf("%d", &x);
            q.push(x);
        }
    }

    return 0;
}
