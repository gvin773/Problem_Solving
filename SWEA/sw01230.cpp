#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

typedef long long ll;

int n, num, x, y, s;
char com;

int main()
{
    onlycc;
    for(int i = 0; i < 10; i++)
    {
        list<int> L;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> num;
            L.push_back(num);
        }

        auto iter = L.begin();
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> com;

            if(com == 'I')
            {
                cin >> x >> y;
                list<int> temp;
                iter = L.begin();
                for(int k = 0; k < x; k++) iter++;
                for(int k = 0; k < y; k++)
                {
                    cin >> num;
                    temp.push_back(num);
                }
                L.splice(iter, temp);
            }

            else if(com == 'D')
            {
                cin >> x >> y;
                iter = L.begin();
                for(int k = 0; k < x; k++) iter++;
                for(int k = 0; k < y; k++) iter = L.erase(iter);
            }
            else
            {
                cin >> y;
                for(int k = 0; k < y; k++)
                {
                    cin >> num;
                    L.push_back(num);
                }
            }
        }

        cout << '#' << i+1 << ' ';

        iter = L.begin();
        for(int j = 0; j < 10; j++, iter++) cout << *iter << ' ';
        cout << '\n';
    }

    return 0;
}
