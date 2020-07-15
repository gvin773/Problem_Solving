#include <stdio.h>

int main(){
	int h, m, minute, nh, nm, ah, am, a;
	scanf("%d %d", &h, &m);
	scanf("%d", &minute);
	nh=minute/60;
	nm=minute-60*nh;
	ah=h+nh;
	am=m+nm;
	if(am>=60){
		ah=ah+am/60;
		a=am/60;
		am=am-60*a;
		if(ah>=24){
			ah=ah%24;
		}
	}
	else if(am<60){
		if(ah>=24){
			ah=ah%24;
		}
	}
	printf("%d %d", ah, am);
	return 0;
}
