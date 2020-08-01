#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

list<int> order, tab;

int main()
{

    int n, k, counter = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int a;
        scanf("%d", &a);
        order.push_back(a);
    }

    for(int i = 0; i < k; i++)
    {
        if(tab.size() < n)
        {
            int push_check = 0;

            for(list<int>::iterator iter = tab.begin(); iter != tab.end(); iter++)
            {
                if(*iter == order.front())
                {
                    push_check = 1;
                    order.pop_front();
                    break;
                }
            }

            if(push_check == 0)
            {
                tab.push_back(order.front());
                order.pop_front();
            }
        }

        else
        {
            int x = 0, y = 0;
            list<int>::iterator iter, iter2, temp;
            for(iter = tab.begin(); iter != tab.end(); iter++)
            {
                if(*iter == order.front())
                {
                    order.pop_front();
                    y = 1;
                    break;
                }
            }

            int last_use = 0;
            for(iter = tab.begin(); iter != tab.end() && y == 0; iter++)
            {
                int ret = 0;
                int i = 1;
                for(iter2 = order.begin(); iter2 != order.end(); iter2++)
                {
                    if(*iter == *iter2)
                    {
                        ret = i;
                        if(i > last_use)
                        {
                            temp = iter;
                            last_use = i;
                        }
                        break;
                    }
                    i++;
                }

                if(ret == 0)
                {
                    tab.erase(iter);
                    tab.push_back(order.front());
                    order.pop_front();
                    x = 1;
                    counter++;
                    break;
                }
            }

            if(x == 0 && y == 0)
            {
                tab.erase(temp);
                tab.push_back(order.front());
                order.pop_front();
                counter++;
            }
        }
    }

    printf("%d", counter);

    return 0;
}
