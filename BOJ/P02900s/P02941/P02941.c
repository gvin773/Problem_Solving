#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, time = 0, num, len;
    char str[101];

    scanf("%s", str);
    len = strlen(str);
    num = len;

    for(i = 0; i < len - 1; i++)
    {
        if(str[i] == 'c' && str[i+1] == '=') //c=
            num--;

        if(str[i] == 'c' && str[i+1] == '-') //c-
            num--;

        if(str[i] == 'd' && str[i+1] == '-') //d-
            num--;

        if(str[i] == 'l' && str[i+1] == 'j') //lj
            num--;

        if(str[i] == 'n' && str[i+1] == 'j') //nj
            num--;

        if(str[i] == 's' && str[i+1] == '=') //s=
            num--;

         if(str[i] == 'z' && str[i+1] == '=') //z=
            num--;
    }

    for(i = 0; i < len - 2; i++)
    {
        if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') //dz=
            num -= 1; //z= -> -1 dz= -> -1 therfore, -2
    }

    printf("%d", num);

    return 0;
}
