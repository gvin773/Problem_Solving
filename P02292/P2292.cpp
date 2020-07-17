#include <iostream>
using namespace std;

int main()
{
    int n, i;

    scanf("%d", &n);

    if(n == 1) i = 1;
    else for(i = 1; 1 + 3*i*(i-1) < n; i++) ;

    printf("%d",  i);

    return 0;
}
