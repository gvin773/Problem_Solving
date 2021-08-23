#include <iostream>
#include <algorithm>
using namespace std;

long long ipow(int a, int b, int c)
{
    if(b == 0) return 1;

    long long ans = ipow(a, b/2, c);
    ans *= ans;
    ans %= c;

    if(b%2 == 1) (ans *= a) %= c;

    return ans;
}

int main()
{
   long long a, b, c;
   scanf("%lld%lld%lld", &a, &b, &c);

   printf("%lld", ipow(a, b, c));
   return 0;
}
