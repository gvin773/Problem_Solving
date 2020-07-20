#include <stdio.h>

int main(){
	int n, m, a[102], sum=0;
	scanf("%d", &n);
	m=n;
	for(; n>0; n--){
		scanf("%d", &a[n]);
	}
	n=m;
	for(; n>0; n--){
		sum=sum+a[n];
	}
	if(sum>=m/2+1){
		printf("Junhee is cute!");
	}
	else
	printf("Junhee is not cute!");
	return 0;
}
