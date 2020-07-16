#include <stdio.h>

int main()
{
	int i, j, a[8], count = 0, up[8], down[8];

	for(i = 0; i < 8; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < 8; i++)
    {
        up[i] = a[i];
        down[i] = a[i];
    }

    if(a[0] == 8)
    {
        for(i = 1; i < 7; i++)
        {
            if(a[1] == 1 && a[i] + 1 == a[i+1])
                count++;
        }

        if(count == 6)
        {
            printf("ascending");
            return 0;
        }

        count = 0;

        for(i = 1; i < 7; i++)
        {
            if(a[1] == 7 && a[i] - 1 == a[i+1])
                count++;
        }

        if(count == 6)
        {
            printf("descending");
            return 0;
        }

        count = 0;
    }

    if(a[7] == 8)
    {
        for(i = 0; i < 7; i++)
        {
            if(a[i] + 1 == a[i+1])
                count++;
        }

        if(count == 7)
        {
            printf("ascending");
            return 0;
        }

        count = 0;

        for(i = 0; i < 7; i++)
        {
            if(a[i] - 1 == a[i+1])
                count++;
        }

        if(count == 7)
        {
            printf("descending");
            return 0;
        }

        count = 0;
    }

    for(i = 0; i < 8; i++)
    {
        if(a[i] == 8)
        {
            for(j = 0; j < i; j++)
            {
                if(a[j] + 1 == a[j+1])
                    count++;
            }

            if(count == i)
            {
                for(j = i+1; j < 8; j++)
                    a[j] += 8;

                for(j = i; j < 8; j++)
                {
                    if(a[j] + 1 == a[j+1])
                        count++;
                }
            }

            if(count == 7)
            {
                printf("ascending");
                return 0;
            }

            count = 0;

            for(j = 0; j < i; j++)
            {
                if(a[j] - 1 == a[j+1])
                    count++;
            }

            if(count == i)
            {
                for(j = i+1; j < 8; j++)
                    a[j] -= 8;

                for(j = i; j < 8; j++)
                {
                    if(a[j] - 1 == a[j+1])
                        count++;
                }
            }

            if(count == 7)
            {
                printf("descending");
                return 0;
            }
        }
    }

    printf("mixed");

    return 0;
}
