#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int L, P, V;

    for(int i = 1; ; i++)
    {
        scanf("%d%d%d", &L, &P, &V);
        if(L == 0 && P == 0 && V == 0) break;
        else printf("Case %d: %d\n", i, L*(V/P) + min(L, V%P));
    }

    return 0;
}
