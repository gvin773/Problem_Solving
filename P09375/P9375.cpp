#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int Case;
    scanf("%d", &Case);

    for(int i = 0; i < Case; i++)
    {
        int n;
        scanf("%d", &n);

        pair<int, string> clothes[31];
        for(int k = 0; k <= 30; k++)
        {
            clothes[k].first = 0;
            clothes[k].second = " ";
        }

        int type = 0;
        for(int j = 0; j < n; j++)
        {
            string temp, temp_type;
            cin >> temp >> temp_type;
            cin.ignore();

            int k;
            for(k = 0; k < type; k++)
            {
                if(temp_type == clothes[k].second)
                    break;
            }

            if(k == type)
            {
                clothes[type].second = temp_type;
                clothes[type].first++;
                type++;
            }

            else
                clothes[k].first++;
        }

        for(int j = 0; j < type; j++)
            clothes[j].first++;

        int ret = 1;
        for(int j = 0; j < type; j++)
            ret *= clothes[j].first;

        printf("%d\n", ret-1);
    }

    return 0;
}
