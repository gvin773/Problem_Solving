#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

typedef long long ll;

int main()
{
    deque<int> d;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        string command;

        cin >> command;

        if(command == "push_front")
        {
            int num;
            scanf("%d", &num);
            d.push_front(num);
        }

        else if(command == "push_back")
        {
            int num;
            scanf("%d", &num);
            d.push_back(num);
        }

        else if(command == "pop_front")
        {
            if(d.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", d.front());
                d.pop_front();
            }
        }

        else if(command == "pop_back")
        {
            if(d.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", d.back());
                d.pop_back();
            }
        }

        else if(command == "size")
            printf("%d\n", d.size());

        else if(command == "empty")
            printf("%d\n", d.empty());

        else if(command == "front")
        {
            if(d.empty()) printf("-1\n");
            else printf("%d\n", d.front());
        }

        else if(command == "back")
        {
            if(d.empty()) printf("-1\n");
            else printf("%d\n", d.back());
        }
    }

    return 0;
}
