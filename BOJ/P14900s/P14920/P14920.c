#include <stdio.h>

int main()
{
	int a;
	int n = 1;
	scanf("%d", &a);

	while(1)
	{
		if (a == 1)
		{
			printf("%d", n);
			break;
		}
		else if(a%2 == 1) //odd
		{
			a = 3*a + 1;
		}
		else //even
		{
			a = a / 2;
		}
	n++;
	}
}
