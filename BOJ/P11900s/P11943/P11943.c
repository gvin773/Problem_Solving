#include <stdio.h>

int main(){
	int a, b, c, d, e, f;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	e=a+d;
	f=b+c;
	if(e>=f)
	printf("%d", f);
	else
	printf("%d", e);
	return 0;
}
