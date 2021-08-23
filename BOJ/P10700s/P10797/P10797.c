#include <stdio.h>

int main(){
    int a, b, c, d, e, f, g, h, i, j, k, sum;
    scanf("%d",&a);
    scanf("%d %d %d %d %d", &b, &c, &d, &e, &f);
    if((a%10)==b){
        g=1;
    }
    else
    g=0;
    if((a%10)==c){
        h=1;
    }
    else
    h=0;
    if((a%10)==d){
        i=1;
    }
    else
    i=0;
    if((a%10)==e){
        j=1;
    }
    else
    j=0;
    if((a%10)==f){
        k=1;
    }
    else
    k=0;
    sum=g+h+i+j+k;
    printf("%d", sum);
    return 0;
}
