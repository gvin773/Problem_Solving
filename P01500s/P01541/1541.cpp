#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char str[51];
    bool pm[30]; //true == '+' false == '-'
    int number[30], intcount = 0, pmcount = 0;

    scanf("%s", str);

    int i, start = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '+')
        {
            pm[pmcount++] = true;
            int num = 0, digit = 1;
            for(int j = i-1; j >= start; j--)
            {
                num += digit*(str[j]-'0');
                digit *= 10;
            }
            start = i+1;
            number[intcount++] = num;
        }

        else if(str[i] == '-')
        {
            pm[pmcount++] = false;
            int num = 0, digit = 1;
            for(int j = i-1; j >= start; j--)
            {
                num += digit*(str[j]-'0');
                digit *= 10;
            }
            start = i+1;
            number[intcount++] = num;
        }
    }

    int num = 0, digit = 1;
    for(int j = i-1; j >= start; j--)
    {
        num += digit*(str[j]-'0');
        digit *= 10;
    }
    number[intcount++] = num;

    int j, ret = number[0];
    for(j = 0; j < pmcount; j++)
    {
        if(pm[j] == false)
            break;

        ret += number[j+1];
    }

    for(; j < pmcount; j++)
        ret -= number[j+1];

    printf("%d", ret);

    return 0;
}
